#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, z1, x2, y2, z2, m, sum = 0;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;

        // we have to minimize the number of (1, 2)
        // pairs and maximize the number of (2, 1) pairs to maximize sum.

        // pairing max num of (2, 1) pairs to maximize (2, 1) pairs
        m = min(z1, y2);
        z1 -= m;
        y2 -= m;
        sum += (2 * m);

        // pairing max num of (0, 2) pairs to minimize (1, 2) pairs
        m = min(x1, z2);
        x1 -= m;
        z2 -= m;

        // pairing max num of (1, 0) pairs to minimize (1, 2) pairs
        m = min(y1, x2);
        y1 -= m;
        x2 -= m;

        // no way than to pair remaining (1, 2) pairs which results in -2
        sum -= (2 * min(y1, z2));
        cout << sum << endl;

    }
    return 0;
}
