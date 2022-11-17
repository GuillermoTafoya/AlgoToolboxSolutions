#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <bitset>
#include <climits>
#include <cstring>


using namespace std;

/*
write a C++ program that reads 5 text files (fixed name, not prompted) containing only characters from 0 to 9, characters from A to F and line breaks
     transmission1.txt
     transmission2.txt
     mcode1.txt
     mcode2.txt
     mcode3.txt

Transmission files contain text characters that represent the sending of data from one device to another.
mcodex.txt files represent malicious code that can be found within a stream.

The program should check whether the contents of the files mcode1.txt, mcode2.txt, and mcode3.,txt are contained in the files transmission1.txt and transmission2.txt and return true or false if the char sequences are contained or No. If true, returns true, followed by exactly one space, followed by the position in the streamX.txt file where the mcodeY.txt code starts

Assuming that malicious code always has "mirrored" code (char palindromes), it would be a good idea to look for this type of code in a stream. The program must then look for "mirrored" code within the streaming files. (palindrome at the chars level, do not get involved at the bit level). The program displays on a single line two integers separated by a space corresponding to the position (starting at 1) where the longest "mirrored" code (palindrome) for each stream file begins and ends. It can be assumed that this type of code will always be found.

Finally the program analyzes how similar the transmission files are, and it should show the starting position and the ending position (starting at 1) of the first file where the longest common substring between both transmission files is found.

input
     nothing, only the 5 files must exist in the same path where the program is executed

output
  Part 1
     (true | false) if the file transmission1.txt contains the code (sequence of chars) contained in the file mcode1.txt
     (true | false) if the file transmission1.txt contains the code (sequence of chars) contained in the file mcode2.txt
     (true | false) if the file transmission1.txt contains the code (sequence of chars) contained in the file mcode3.txt
     (true | false) if the file transmission2.txt contains the code (sequence of chars) contained in the file mcode1.txt
     (true | false) if the file transmission2.txt contains the code (sequence of chars) contained in the file mcode2.txt
     (true | false) if the file transmission2.txt contains the code (sequence of chars) contained in the file mcode3.txt
  part 2
     startPosition endPosition (for stream file1)
     startPosition endPosition (for stream file2)
  part 3
      startPosition endPosition (from longest common substring between stream files)*/



#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

// KMP algorithm for pattern searching
// We use this to find the malware is in the transmission file, returns the
// starting and ending position of the malware.
void computeLPSArray(std::string pat, int M, int *lps);

std::pair<int, int> KMPsearch(std::string pat, std::string txt) {
  int M = pat.size();
  int N = txt.size();

  // create lps[] that will hold the longest prefix suffix
  // values for pattern
  int lps[M];

  // Preprocess the pattern (calculate lps[] array)
  computeLPSArray(pat, M, lps);

  int i = 0; // index for txt[]
  int j = 0; // index for pat[]
  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == M) {
      // printf("Found pattern at index %d ", i - j);
      return std::make_pair((i - j + 1), (i - j + M));
      j = lps[j - 1];
    }

    // mismatch after j matches
    else if (i < N && pat[j] != txt[i]) {
      // Do not match lps[0..lps[j-1]] characters,
      // they will match anyway
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
  return std::make_pair(-1, -1);
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(std::string pat, int M, int *lps) {
  // length of the previous longest prefix suffix
  int len = 0;

  lps[0] = 0; // lps[0] is always 0

  // the loop calculates lps[i] for i = 1 to M-1
  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else // (pat[i] != pat[len])
    {
      // This is tricky. Consider the example.
      // AAACAAAA and i = 7. The idea is similar
      // to search step.
      if (len != 0) {
        len = lps[len - 1];

        // Also, note that we do not increment
        // i here
      } else // if (len == 0)
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}

// Función que lee el archivo de entrada e identifica si hay un malware
bool presenciasMalware(std::string txt, std::string malware) {
    int linea = 0;
    int startPos, endPos;


    std::pair<int, int> temp = KMPsearch(malware, txt);
    startPos = temp.first;
    endPos = temp.second;
    if (startPos == -1) {
    return false;
    }
    std::cout << "Malware encontrado entre la posicion " << startPos << " y " << endPos << '\n';
    return true;
}

void printSub(string str, int low, int high)
{
    std::cout << "Longest palindrome substring is: ";
    for (int i = low; i <= high; ++i)
        cout << str[i];
    cout<<'\n';
    std::cout << "Starting idx: " << low << " Ending idx: " << high << '\n';
    std:: cout << "Longest palindrome length is: " << high - low + 1 << '\n' << '\n';

}

int longPal(std::string str)
{
    int n = str.size();
    bool grid[n][n];

    memset(grid, 0, sizeof(grid));
  
    int maxLength = 1;
  
    for (int i = 0; i < n; ++i)
        grid[i][i] = true;
  
    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            grid[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
  
    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
            if (grid[i + 1][j - 1] && str[i] == str[j]) {
                grid[i][j] = true;
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    printSub(str, start, start + maxLength - 1);
    return maxLength;
}

// Reverse de malware
std::string reverseMalware(std::string malware) {
  std::string reverseMalware;
  std::string::reverse_iterator it;
  for (it = malware.rbegin(); it != malware.rend(); ++it) {
    reverseMalware.push_back(*it);
  }
  return reverseMalware;
}

std::string readFile(std::string fileName) {
    std::ifstream t(fileName);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string txt = buffer.str();
    return txt;
}

void manageIsPresent(bool t){
    std::cout << "Is present?\n";
    if (t){
        std::cout << "true" << '\n';
    } else {
        std::cout << "false" << '\n';
    }
}

void LCSubStr(string s, string t, int n, int m)
{
   
    // Create DP table
    int dp[2][m + 1];
    int res = 0;
 
    // Print the starting index of the longest common substring and the ending index
    int endingIndex = 0;
    int startingIndex = 0;

    // Iterate over the strings
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i % 2][j] = 0;
            else if (s[i - 1] == t[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                if (res < dp[i % 2][j]) {
                    res = dp[i % 2][j];
                    endingIndex = i;
                }
            }
            else
                dp[i % 2][j] = 0;
        }
    }
    startingIndex = endingIndex - res;
    std::cout << "Longest common substring is: ";
    for (int i = startingIndex; i < endingIndex; i++)
        std::cout << s[i];
    std::cout << '\n';
    std::cout << "Starting idx: " << startingIndex << " Ending idx: " << endingIndex << '\n';
    std::cout << "Longest common substring length is: " << res << '\n' << '\n';
}

int main() {
    // Read the whole file into a string
    std::string malware1 = readFile("mcode1.txt");
    std::string malware2 = readFile("mcode2.txt");
    std::string malware3 = readFile("mcode3.txt");

    std::string transmicion1 = readFile("transmission1.txt");
    std::string transmicion2 = readFile("transmission2.txt");

    manageIsPresent(presenciasMalware(transmicion1, malware1));
    manageIsPresent(presenciasMalware(transmicion1, malware2));
    manageIsPresent(presenciasMalware(transmicion1, malware3));

    std::cout << '\n';

    longPal(transmicion1) << '\n';
    longPal(transmicion2) << '\n';

    LCSubStr(transmicion1, transmicion2, transmicion1.size(), transmicion2.size());

    return 0;
}
