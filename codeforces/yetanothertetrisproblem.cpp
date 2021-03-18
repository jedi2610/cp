#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, x, odd = 0, even = 0;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> x;
            if (x & 1)
                odd++;
            else
                even++;
        }
        if (even == n || odd == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
