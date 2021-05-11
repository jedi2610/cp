#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1375/A */
int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    ll temp;
    cin >> n;
    while (n--) {
      cin >> temp;
      if (n % 2)
        cout << ((temp >= 0) ? temp : -temp);
      else
        cout << ((temp <= 0) ? temp : -temp);
      cout << " ";
    }
    cout << endl;
  }
  return 0;
}
