#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    set<int> s(a, a + n);
    int bestDays = 100000;

    for (int i : s) {
      int days = 0;
      for (int j = 0; j < n; j++)
        if (a[j] != i) {
          days++;
          j += k - 1;
        }
      bestDays = min(bestDays, days);
    }
    cout << bestDays << endl;
  }
  return 0;
}
