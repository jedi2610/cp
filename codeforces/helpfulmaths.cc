#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {

    string s;
    cin >> s;

    s.erase(remove(s.begin(), s.end(), '+'), s.end());
    sort(s.begin(), s.end());

    int i = 0;
    for (i=0; i<s.length()-1; i++)
        cout << s[i] << "+";
    cout << s[i];

    return 0;
}
