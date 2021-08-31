#include <algorithm>
#include <iostream>

using namespace std;
using ll = int64_t;

int main() {
  string s;
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  int a[n][m], b[n][m], c[n][m], tot = n * m;

  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++)
      cin >> a[i][j] >> b[i][j] >> c[i][j];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      int items = k, prof = 0;
      pair<int, int> profit[m];
      for (int l = 0; l < m; l++) {
        profit[l] = make_pair(a[j][l] - b[i][l], c[j][l]);
      }
      sort(profit, profit + m);

      for (int l = 0; profit[l].first < 0 && items; l++) {
        int temp = min(profit[l].second, items);
        items -= temp;
        prof += temp * -profit[l].first;
      }
      ans = max(ans, prof);
    }
  }

  cout << ans;
  return 0;
}
