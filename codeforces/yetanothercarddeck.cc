#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1511/C */

void print(vector<int> color) {
  for (int i = 0; i < color.size(); i++)
    cout << color[i] << " ";
  cout << endl;
}

int main() {

  ll n, q, num;
  cin >> n >> q;
  vector<int> color;
  for (ll i = 0; i < n; i++) {
    cin >> num;
    color.push_back(num);
  }

  for (ll i = 0; i < q; i++) {
    cin >> num;
    ll idx = find(color.begin(), color.end(), num) - color.begin();
    cout << idx + 1 << " ";
    rotate(color.begin(), color.begin() + idx, color.begin() + idx + 1);
    /* print(color); */
  }
  return 0;
}
