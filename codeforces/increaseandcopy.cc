#include<iostream>
#include<cmath>

using namespace std;
using ll = long long;

int main() {

    int t;
    cin >> t;
    while (t--) {
        ll n, ans = 1e9;
        cin >> n;
        for (int i=1; i*i <= n; i++)
            ans = min<ll>(ans, i-1 + ((n-1)/i));
        cout << ans << endl;
    }
    return 0;
}
