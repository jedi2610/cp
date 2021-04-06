#include <iostream>

using namespace std;
using ll = long long;

/* https://codeforces.com/blog/entry/87356 */
int main() {

  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll cf = (n + k - 1) / k;
    cout << ((cf * k) + n - 1) / n << endl;
  }
  return 0;
}
