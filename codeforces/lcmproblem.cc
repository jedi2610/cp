#include<iostream>
#define ll long long

using namespace std;

int main() {

    ll t, l, r, x, y;
    cin >> t;
    while (t--) {
        cin >> l >> r;

        x = l;
        y = l * 2;

        if (y <= r)
            cout << x << " " << y << endl;
        else
            cout << "-1 -1" << endl;
    }
    return 0;
}
