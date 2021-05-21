#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1165/B */
int main() {

  int n, k = 1;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  for (int i = 0; i < n; i++) {
    if (a[i] < k) {
      continue;
    }
    k++;
  }
  cout << k - 1 << endl;
  return 0;
}
