#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int t, negNum = 0, zeros = 0;
    cin >> t;
    ll a[t], turns = 0;

    for (int i=0; i<t; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            turns++;
            zeros++;
            continue;
        }

        if (a[i] < 0) {
            negNum++;
            turns += (-1 - a[i]);
        } else {
            turns += (a[i] - 1);
        }
    }

    if (negNum & 1 && zeros == 0)
        turns += 2;
    cout << turns << endl;

    return 0;
}
