#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {

        ll a, b, c;
        cin >> a >> b >> c;
        ll sum = a + b + c;

        if (sum % 9) {
            cout << "NO" << endl;
        } else {
            ll minNum = min(min(a, b), c);
            if (minNum < (sum/9))
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}
