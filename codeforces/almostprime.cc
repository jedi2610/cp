#include<iostream>
#include<vector>

using namespace std;
using ll = int64_t;

int main() {

    int n, L = 3000, ans = 0;
    cin >> n;

    vector<int> DP(L+1, 0);
    for (int i = 1; i<=3000; i++) {
        for(int j = i; j<=3000; j+=i)
            DP[j]++;
    }

    vector<int> A(L+1, 0);
    for (int i = 1; i<=3000; i++) {
        if (DP[i] == 2) {
            for (int j = i; j<=3000; j+=i) {
                A[j]++;
            }
        } else {
            continue;
        }
    }

    for (int i = 0; i<=n; i++) {
        if (A[i] == 2)
            ans++;
    }

    cout << ans;
    return 0;
}
