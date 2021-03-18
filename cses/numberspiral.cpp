#include<iostream>

using namespace std;
using ll = long long;

void findNumber(ll r, ll c) {
   
    if(r > c) {
        // if r is greater than cj
        if (r%2 != 0) {
            // if r is odd
            r--;
            cout << r * r + c;
        } else {
            // if r is even
            cout << r * r - c + 1;
        }
    } else {
        // if c is greater than r
        if (c%2 != 0) {
            // if r is odd
            cout << c * c - r + 1;
        } else {
            // if r is even
            c--;
            cout << c * c + r;
        }
    }
}

int main(int argc, char *argv[])
{
    ll n, x, y;
    cin >> n;
    // if row or col is odd then the starting number is odd too
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        findNumber(x, y);
        cout << endl;
    }
    return 0;
}
