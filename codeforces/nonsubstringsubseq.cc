#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, q;
        string s;
        cin >> n >> q;
        cin >> s;

        while (q--) {
            int i, j;
            bool bad = false;
            cin >> i >> j;
            int iPos = s.find(s[i-1]);
            int jPos = s.find_last_of(s[j-1]);

            if (iPos+1 == i && jPos+1 == j)
                bad = true;

            cout << (bad ? "NO" : "YES") << endl;
        }
    }

    return 0;
}
