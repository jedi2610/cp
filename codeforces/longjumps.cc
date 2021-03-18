#include<iostream>
#include<vector>

using namespace std;
using ll = int64_t;

vector<ll> DP;
ll n = 0;

ll solve(ll a[], ll i) {

    if (i >= n)
        return 0;

    if (DP[i] != -1)
        return DP[i];

    DP[i] = a[i];
    DP[i] += solve(a, i+a[i]);

    return DP[i];
}

int main() {

    int t;
    cin >> t;
    while(t--) {

        cin >> n;
        ll a[n], score = 0;
        DP = vector<ll>(n, -1);

        for (int i=0; i<n; i++)
            cin >> a[i];

        /* a more elegant solution */
        /* ll F[n];
        for (int i = n; i >= 1; i--) {
		    F[i] = a[i];
		    if (i + a[i] <= n) F[i] += F[i + a[i]];
	    }
        for (int i = 0; i <  n; i++)
        score = max(score, F[i]) */

        for (int i=0; i<n; i++) {
            ll tempScore = solve(a, i);
            score = max(score, tempScore);
        }

        cout << score << endl;
    }
    return 0;
}
