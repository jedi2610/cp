#include<iostream>
#include<cmath>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int turn = 1;
        ll n, ans;
        cin >> n;
        ans = n;

        cout << "2" << endl;
        for (int i=n-1; i>0; i--) {
            cout << ans << " " << i << endl;
            ans = (ans + i + 1) / 2;
        }
    }
    return 0;
}
