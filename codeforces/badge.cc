#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[1000], seen[1000], n;

int dfs(int x) {
  seen[x] = 1;
  if (seen[a[x]])
    return a[x];
  else
    return dfs(a[x]);
}

/* https://codeforces.com/problemset/problem/1020/B */
int main() {

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  for (int i = 0; i < n; i++) {
    memset(seen, 0, sizeof(int) * n);
    cout << dfs(i) + 1 << " ";
  }

  return 0;
}
