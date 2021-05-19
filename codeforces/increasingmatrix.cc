#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1231/C */
int main() {
  int n, m, sum = 0;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      sum += a[i][j];
    }

  for (int i = n - 2; i > 0; i--) {
    for (int j = m - 2; j > 0; j--) {
      if (a[i][j] == 0) {
        a[i][j] = min(a[i + 1][j], a[i][j + 1]) - 1;
        sum += a[i][j];
      }
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i - 1][j] >= a[i][j] || a[i][j - 1] >= a[i][j]) {
        cout << "-1" << endl;
        exit(0);
      }
    }
  }

  cout << sum << endl;

  return 0;
}
