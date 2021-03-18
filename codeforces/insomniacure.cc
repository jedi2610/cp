#include<iostream>
#include<set>

using namespace std;
using ll = int64_t;

int main() {
    
    int k, l, m, n;
    ll d, ct = 0;
    cin >> k >> l >> m >> n >> d;

    int klmn[4] = {k, l, m, n};
    set<int> track;

    if (k == 1 || l == 1 || m == 1 || n == 1) {
        cout << d;
        return 0;
    }

    for (int i: klmn) {
        for (int j=i; j<=d; j+=i) {
            track.insert(j);
        }
    }
    cout << track.size();

    return 0;
}
