#include<iostream>

using namespace std;
using ll = int64_t;

int n, m, red[100], blue[100];

ll solve() {

    ll ansI = -10e4, scoreI = 0, ansJ = -10e4, scoreJ = 0;
    for (int i=0; i<n; i++) {
        scoreI += red[i];
        ansI = max(ansI, scoreI);
    }

    for (int j=0; j<m; j++) {
        scoreJ += blue[j];
        ansJ = max(ansJ, scoreJ);
    }

    return (max<ll>(0LL, ansI) + max<ll>(0LL, ansJ));
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        // n = red and m = blue

        cin >> n;
        for (int i=0; i<n; i++)
            cin >> red[i];
        cin >> m;
        for (int i=0; i<m; i++)
            cin >> blue[i];

        ll ans = solve();
        cout << ans << endl;
    }
    return 0;
}
