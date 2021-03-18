#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {

        ll n, k = 0;
        cin >> n;
        ll a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];

        while (k < n && a[k] == 1)
            k++;

        if ((k % 2) ^ (k == n))
            cout << "Second" << endl;
        else
            cout << "First" << endl;
    }
    return 0;
}
