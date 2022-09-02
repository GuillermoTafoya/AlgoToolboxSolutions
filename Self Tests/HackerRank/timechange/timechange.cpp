#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int hour = 0, length = s.size();
    hour += stoi(s.substr(0,s.find(':')));
    if (hour == 12){
        hour = 0;
    }
    //Parse am or pm
    if (s.substr(length-2,2)=="PM"){
        hour+=12;
    } 
    s = s.substr(0,length-2);
    s = s.substr(s.find(':'),length);
    s = to_string(hour).size() < 2 ? "0"+to_string(hour) + s : to_string(hour) + s;
    cout << s;
    
    return 0;
}