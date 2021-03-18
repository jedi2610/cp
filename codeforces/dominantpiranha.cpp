#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    ll t;
    cin >> t;
    while (t--) {

        ll n, ans = -1, max = 0;
        cin >> n;
        ll a[n];

        for (int i=0; i<n; i++) {
            cin >> a[i];
            max = std::max<long long>(max, a[i]);
        }
        for (int i=0; i<n; i++) {
            if (a[i] != max) continue;
            if (i > 0 && a[i-1] < max) ans = i + 1;
            if (i < n-1 && a[i+1] < max) ans = i + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
