#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1417/B */
/* Link to editorial: https://codeforces.com/blog/entry/83036 */
/* my answer is actually right afaik */

/* int main() {

  int t;
  cin >> t;
  while (t--) {
    ll n, bad;
    cin >> n >> bad;
    vector<ll> comp;
    for (ll i = 0; i < n; i++) {
      ll num;
      cin >> num;
      vector<ll>::iterator it = find(comp.begin(), comp.end(), num);
      if (it != comp.end()) {
        cout << "0 ";
        remove(comp.begin(), comp.end(), num);
      } else {
        cout << "1 ";
        comp.push_back(bad - num);
      }
    }
    cout << endl;
  }
  return 0;
} */

int main() {

  int t;
  cin >> t;
  while (t--) {
    ll n, bad, totMid = 0, temp;
    char ans;
    cin >> n >> bad;
    for (ll i = 0; i < n; i++) {
      cin >> temp;
      if (bad % 2 == 0 && 2 * temp == bad) {
        cout << ((totMid % 2) ? "0 " : "1 ");
        totMid++;
      } else if (2 * temp < bad)
        cout << "0 ";
      else
        cout << "1 ";
    }
    cout << endl;
  }
  return 0;
}
