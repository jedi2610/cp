#include<iostream>

using namespace std;
using ll = long long;

int main() {

    int n, v, ans;
    cin >> n >> v;
    if (n - 1 <= v)
        ans = n-1;
    else {
        ans = v;
        for (int i = 2; i <= n - v; i++)
            ans += i;
    }

    cout << ans;
    return 0;
}
