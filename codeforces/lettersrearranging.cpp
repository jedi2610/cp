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
        sort(s.begin(), s.end());
        if (s[0] == s.back())
            cout << "-1" << endl;
        else
            cout << s << endl;
    }
    return 0;
}
