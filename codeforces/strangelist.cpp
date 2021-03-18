#include<iostream>
#include<queue>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {

        ll n, x, sum = 0, temp;
        bool end = false;
        queue<ll> s;
        cin >> n >> x;
        for (int i=0; i<n; i++) {
            cin >> temp;
            if (temp % x == 0 && !end) {
                sum += temp;
                ll div = temp/x;
                for (int j=0; j<x; j++) {
                    s.push(div);
                }
            }
            else {
                end = true;
                sum += temp;
            }
        }
        while (!s.empty()) {
            ll ele = s.front();
            s.pop();
            if (ele % x == 0 && !end) {
                sum += ele;
                ll div = ele/x;
                for (ll j=0; j<x; j++) {
                    s.push(div);
                }
            }
            else {
                sum += ele;
                while (!s.empty()) {
                    ll ele = s.front();
                    s.pop();
                    sum += ele;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
