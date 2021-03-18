#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
using ll = int64_t;

int main() {

    ll n;
    cin >> n;
    ll a[n];

    for (int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a+n);
    ll sum = 0;

    for (int i=0, j=n-1; i<n/2; i++,j--) {
        sum += pow((a[i] + a[j]), 2);
    }
    cout << sum;
    return 0;
}
