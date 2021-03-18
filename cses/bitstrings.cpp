#include <cstdint>
#include<iostream>

using namespace std;
using ll = int64_t;

ll MOD = 1e9 + 7;

ll MUL(ll x, ll y) {
    return (x * y) % MOD;
}

ll POW(ll a, ll e) {
    if (e == 0)
        return 1LL;
    else if (e%2 == 1)
        return MUL(a, POW(a, e-1));
    else
        return POW(MUL(a, a), e/2);
}


int main() {

    ll e;
    cin >> e;
    ll ans = POW(2, e);
    cout << ans;
    return 0;
}
