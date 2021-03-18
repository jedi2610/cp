#include<iostream>
#include<algorithm>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        reverse(a, a+n);
        for (int i=0; i<n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
