#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

  int n;
  cin >> n;
  double ans = 0;
  for (float i = 1; i <= n; i++) {
    ans += (1.0 / i);
  }
  cout << ans << endl;
  return 0;
}
