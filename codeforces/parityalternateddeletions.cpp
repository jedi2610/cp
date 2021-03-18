#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {

    int n, noOdd = 0, noEven = 0;
    cin >> n;
    ll x, even[n+1], odd[n+1];

    for (int i=0; i<n; i++) {
        cin >> x;
        if (x & 1) {
            odd[noOdd] = x;
            noOdd++;
        }
        else {
            even[noEven] = x;
            noEven++;
        }
    }

    ll sum = 0;
    int diff = noEven - noOdd;
    if (abs(diff) == 1 || noEven == noOdd) {
        sum = 0;
    } else {
        if (diff > 0) {
            sort(even, even + noEven);
            for (int i=0; i<diff-1; i++)
                sum += even[i];
        } else {
            diff = -diff;
            sort(odd, odd + noOdd);
            for (int i=0; i<diff-1; i++)
                sum += odd[i];
        }
    }
    cout << sum;

    return 0;
}
