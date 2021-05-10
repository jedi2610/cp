#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1447/B */
int main() {

  int t;
  cin >> t;
  while (t--) {
    int n, m, temp, count = 0, sum = 0, minNum = 10000;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> temp;
        if (temp <= 0)
          count++;
        temp = abs(temp);
        minNum = min(minNum, temp);
        sum += temp;
      }
    }
    if (count % 2)
      sum -= (2 * minNum);
    cout << sum << endl;
  }
  return 0;
}
