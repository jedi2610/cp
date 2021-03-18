#include<iostream>

using namespace std;
using ll = long long;

int main() {

    int t;
    cin >> t;
    while (t--) {

        ll n, i;
        cin >> n;
        ll binLen = (4 * n) - n;
        for (i=0; i<(binLen/4); i++)
            cout << "9";
        for (; i<n; i++)
            cout << "8";
        cout << endl;
    }
    return 0;
}
