#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int len = s.length();
        if (s[0] != ')' && s.back() != '(' && len % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        /* int openPos = s.find('('); */
        /* int closePos = s.find(')'); */
        /* int count = std::count(s.begin(), s.end(), '?'); */

        /* if (openPos > closePos) { */
        /*     int before = std::count(s.begin(), s.begin()+closePos, '?'); */
        /*     int after = std::count(s.begin()+openPos, s.end(), '?'); */
        /*     int middle = std::count(s.begin()+closePos, s.begin()+openPos, '?'); */

        /*     if (middle % 2 == 0) { */
        /*         if (before == 0 || after == 0) */
        /*             cout << "NO" << endl; */
        /*         else if (before % 2 == 0 && after % 2 == 0 && before == after) */
        /*             cout << "YES" << endl; */
        /*         else if (before % 2 && after % 2) */
        /*             cout << "YES" << endl; */
        /*     } else */
        /*         cout << "NO" << endl; */
        /* } else if (count % 2) */
        /*     cout << "NO" << endl; */
        /* else */ 
        /*     cout << "YES" << endl; */
    }
    return 0;
}

// ?)(?
// ?)?(??
// ??)?(
