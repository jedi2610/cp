#include<iostream>
#include<cmath>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        ll n, x, min = 0, max = 0, temp, sum = 0;
        cin >> n >> x;

        for (int i=0; i<n; i++) {
            cin >> temp;
            max += ceil((double) temp/x);
            sum += temp;
            if (sum % x == 0) {
                min += (sum/x);
                sum = 0;
            }
        }
        min += ceil((double) sum/x);
        cout << min << " " << max << endl;
    }

    return 0;
}
