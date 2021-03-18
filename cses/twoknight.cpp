#include<iostream>

using namespace std;
using ll = long long;

ll calc(ll n) {

    ll ans;
    ans = (n * n * (n*n-1) - 8 - 24 - (n-4) * 16 - 16 - 24 * (n-4) - 8 * (n-4) * (n-4));
    return ans;
}


int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    for(ll i=1; i<=t; i++) {
        cout << calc(i)/2 << endl;
    }
    return 0;
}
