#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1521/A */
int main() {

  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    if (b == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << a << " " << a * b << " " << a * (b + 1) << endl;
    }
  }
}
