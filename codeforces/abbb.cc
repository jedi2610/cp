#include<iostream>
#include<string>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll stack = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == 'B' && stack)
                stack--;
            else
                stack++;
        }
        cout << stack << endl;
    }
    return 0;
}
