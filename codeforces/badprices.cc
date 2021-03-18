#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0, rightMin;
        cin >> n;
        int a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];
        rightMin = a[n-1];
        for (int i=n-1; i>=0; i--) {
            if (a[i] > rightMin)
                ans++;
            rightMin = min(a[i], rightMin);
        }
        cout << ans << endl;
    }
    return 0;
}
