#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {

    ll n, mid;
    int i, j;
    cin >> n;
    mid = n/2;
    ll a[n];
    for (i=0; i<n; i++)
        cin >> a[i];

    sort(a, a+n);
    if (n % 2)
        cout << n/2 << endl;
    else
        cout << n/2 - 1 << endl;
    for (i=mid, j=0; i<n && j<mid; i++,j++)
        cout << a[i] << " " << a[j] << " ";
    if (n % 2)
        cout << a[i];
    return 0;
}
