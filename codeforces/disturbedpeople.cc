#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1077/B */
int main() {

  int n, ans = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 1; i < n - 1; i++) {
    if (a[i] == 1)
      continue;
    if (a[i - 1] == 1 && a[i + 1] == 1) {
      ans++;
      a[i + 1] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
