#include <cstdint>
#include <cstdlib>
#include<iostream>

using namespace std;
using ll = int64_t;

void checkPiles(ll a, ll b) {

    ll x = (2 * a - b);
    ll y = (2 * b - a);

    if (x >= 0 && x % 3 == 0 && y >= 0 && y % 3 == 0)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int main() {

    ll t, a, b;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> a >> b;
        checkPiles(a, b);
    }
    return 0;
}
