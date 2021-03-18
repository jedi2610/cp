#include<iostream>

using namespace std;
using ll = long long;

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x < y) {
            ll temp = x;
            x = y;
            y = temp;
        }

        if (a + a <= b)
            cout << (x + y) * a << endl;
        else
            cout << (y * b) + ((x - y) * a) << endl;
    }
    return 0;
}
