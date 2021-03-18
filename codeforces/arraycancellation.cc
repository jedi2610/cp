#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {

        ll n, pos = 0, ans = 0, x;
        cin >> n;
      
        // a more elegant solution than mine 
        // but it's not that intuitive atleast to me

        /* ll cur = 0; */
        /* for (int i = 0; i < n; ++i) { */
			/* long long x; cin >> x; */
			/* cur = max(0LL, cur + x); */
		/* } */

        for (int i=0; i<n; i++) {
            cin >> x;
            pos += x;

            if (pos < 0) {
                ans += abs(pos);
                pos = max<ll>(0LL, pos);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
