#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/contest/1335/problem/C */
int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      a[val]++;
    }
    int maxCount = *max_element(a.begin(), a.end());
    int diff = n + 1 - count(a.begin(), a.end(), 0);
    cout << max(min(maxCount, diff - 1), min(maxCount - 1, diff)) << endl;
  }
  return 0;
}
