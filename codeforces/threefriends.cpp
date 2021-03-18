#include<iostream>
#include<algorithm>
#include <limits>

using namespace std;
using ll = int64_t;

ll calcDist (ll a, ll b, ll c) {
    return abs(a-b) + abs(a-c) + abs(b-c);
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        ll a, b, c, minVal;
        cin >> a >> b >> c;
        minVal = numeric_limits<long long>::max();

        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                for (int k=-1; k<=1; k++) {
                    minVal = min(minVal, calcDist(a+i, b+j, c+k));
                }
            }
        }

        cout << minVal << endl;
    }

    return 0;
}
