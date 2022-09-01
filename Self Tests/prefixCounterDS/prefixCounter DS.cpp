#include <iostream>
#include <string>
#include <vector>
/*
Implement a data structure to count the number of strings with a given prefix.
Assume a large number of prefix counts will be requested for the same
dictionary, and split your code to setup (performed once per dictionary) and
count (performed per prefix).
data_structure = MyDataStructure(["app", "apple", "appetizer",
"elephant", "aapp"])
data_structure.Count("app") == 3
*/

class trieNode {    
    public:
        std::vector<trieNode> children;
        char letter;
        int count;
        trieNode (char letter, int count) {
            this->letter = letter;
            this->count = count;
        }
        
        void addChild (char letter, int count) {
            this->children.push_back(trieNode(letter, count));
        }
        int getChild (char letter){
            for (int i = 0; i < this->children.size(); i++) {
                if (this->children[i].letter == letter) {
                    return i;
                }
            }
            return -1;
        }
};

class MyDataStructure {
    private:
        trieNode root = trieNode(' ', 0);
    public:
        void addWordToTrie(std::string word){
            trieNode *current = &root;
            for (int i = 0; i < word.size(); i++) {
                int index = current->getChild(word[i]);
                if (index == -1) {
                    current->addChild(word[i], 1);
                    index = current->children.size() - 1;
                } else {
                    current->children[index].count++;
                }
                current = &current->children[index];
            }
        }
        int countPrefix(std::string prefix){
            trieNode *current = &root;
            for (int i = 0; i < prefix.size(); i++) {
                int index = current->getChild(prefix[i]);
                if (index == -1) {
                    return 0;
                } else {
                    current = &current->children[index];
                }
            }
            return current->count;
        }
        MyDataStructure(std::vector<std::string> words) {
            for (int i = 0; i < words.size(); i++) {
                this->addWordToTrie(words[i]);
            }
        }
};

int main(){
    std::string prefix;
    std::cin >> prefix;
    std::vector<std::string> words = {"app", "apple", "appetizer", "elephant", "aapp"};
    MyDataStructure data_structure = MyDataStructure(words);
std::cout << data_structure.countPrefix(prefix) << '\n';
    return 0;
}