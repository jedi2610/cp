#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    ll a, b, ct;
    cin >> t;

    while (t--) {

        cin >> a >> b;
        if (a == b) {
            cout << "0" << endl;
            continue;
        }

        ll ans = 0;
        if (a > b)
            ans = (a/10) - (b/10);
        else
            ans = (b/10) - (a/10);

        if (a > b) {
            if (b % 10 < a % 10)
            ans += 1;
        } else {
            if (b % 10 > a % 10)
            ans += 1;
        }
        cout << ans << endl;
    }
}
