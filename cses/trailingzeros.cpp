#include <cstdint>
#include<iostream>

using namespace std;
using ll = int64_t;

ll MOD = 1e9 + 7;

ll findTrailingZeros(ll n) {
    
    ll count = 0;
    for (int i=5; n/i >= 1; i*=5)
        count += n/i;
    return count;
}

int main() {

    ll n;
    cin >> n;
    ll ans = findTrailingZeros(n);
    cout << ans;
    return 0;
}
