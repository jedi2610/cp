#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    ll num;
    ll total = (n * (n+1)) / 2;
    for (int i=0; i<n-1; i++) {
        cin >> num;
        total -= num;
    }
    cout << total;
    return 0;
}
