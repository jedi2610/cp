#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, ok = 0;
        cin >> n;
        ll a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];

        sort(a, a+n);
        for (int i=0; i<n-1; i++) {
            if (a[i] == a[i+1]) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "YES": "NO") << endl;
    }
    return 0;
}
