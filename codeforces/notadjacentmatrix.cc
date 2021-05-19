#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1520/C */
int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << "-1" << endl;
      continue;
    }
    int a[n * n], idx = 0;
    for (int i = 1; i <= n * n; i += 2)
      a[idx++] = i;
    for (int i = 2; i <= n * n; i += 2)
      a[idx++] = i;

    for (int i = 0; i < n * n; i++) {
      if (!(i % n) && i)
        cout << endl;
      cout << a[i] << " ";
    }
  }
}
