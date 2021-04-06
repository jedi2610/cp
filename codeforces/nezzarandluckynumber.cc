#include <iostream>

using namespace std;
using ll = long long;

void solve(ll x, ll d) {

  int lowerbound = 10 * d;
  if (x >= lowerbound) {
    cout << "YES\n";
    return;
  } else {
    while (x > 0) {
      x -= d;
      if (!(x % 10)) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int q;
    ll d, x;
    cin >> q >> d;
    for (int i = 0; i < q; i++) {
      cin >> x;
      solve(x, d);
    }
  }
  return 0;
}
