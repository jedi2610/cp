#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {

    int t;
    cin >> t;
    while (t--) {
        ll n, x, i = 0, sum = 0;
        cin >> n >> x;
        ll a[n];
        for (i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        reverse(a, a+n);
        i = 0;
        while(i < n && sum + a[i] >= (i+1) * x) {
            sum += a[i];
            i++;
        }
        cout << i << endl;
    }
    return 0;
}
