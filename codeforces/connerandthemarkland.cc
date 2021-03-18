#include<iostream>
#include<set>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        ll n, s, temp, l, u;
        int k;
        set<ll> a;
        cin >> n >> s >> k;
        l = u = s;

        for (int i=0; i<k; i++) {
            cin >> temp;
            a.insert(temp);
        }

        // two pointer method
        while (l > 0 || u <= n) {
            if (l > 0 && a.find(l) == a.end()) {
                cout << s - l << endl;
                break;
            }
            else if (u <= n && a.find(u) == a.end()) {
                cout << u - s << endl;
                break;
            }
            l--; u++;
        }
    }
    return 0;
}
