#include<iostream>

using namespace std;
using ll = long long;

int main() {

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if ((n % 2 == k % 2) && (k * k <= n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
