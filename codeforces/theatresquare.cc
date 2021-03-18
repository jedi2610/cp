#include<iostream>

using namespace std;
using ll = long long;

int main() {

    ll n, m, a;
    cin >> n >> m >> a;
    if (n % a) n = (n/a) + 1;
    else n = (n/a);

    if (m % a) m = (m/a) + 1;
    else m = (m/a);

    cout << m * n << endl;
}
