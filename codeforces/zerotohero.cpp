#include<iostream>
#include<cmath>

using namespace std;
using ll = unsigned long long;

int main() {

    int t;
    cin >> t;

    while (t--) {
        ll n, k, ct = 0;
        cin >> n >> k;

        while (n != 0) {
            if (n % k == 0) {
                n /= k;
                ct++;
            }
            else {
                ll rem = n % k;
                n-=rem;
                ct += rem;
            }
        }
        cout << ct << endl;
    }
    return 0;
}
