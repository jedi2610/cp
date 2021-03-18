#include<iostream>
#include<algorithm>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int perm[n];
        bool res = false;
        for (int i=0; i<n; i++)
            cin >> perm[i];

        for (int i=0; i<n-2; i++) {
            if (perm[i] < perm[i+1] && perm[i+1] > perm[i+2]) {
                cout << "YES" << endl;
                cout << i+1 << " " << i+2 << " " << i+3 << endl;
                res = true;
                break;
            }
        }

        if (!res)
            cout << "NO" << endl;
    }
    return 0;
}
