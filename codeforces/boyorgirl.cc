#include<iostream>
#include<string>
#include<set>

using namespace std;

int main() {

    string username;
    set<char> chars;
    cin >> username;

    for (int i=0; i<username.length(); i++)
        chars.insert(username[i]);

    if (chars.size() & 1)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";

    return 0;
}
