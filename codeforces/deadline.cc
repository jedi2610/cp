#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1288/A */
int main() {

  int t;
  cin >> t;
  while (t--) {
    ll n, d;
    cin >> n >> d;
    ll max = (ll)sqrt(d), x;
    ll c = ceil(max - 1), f = floor(max - 1);

    if (ceil(f + ((double)d / (double)(f + 1))) <= n)
      cout << "YES";
    else if (ceil(c + ((double)d / (double)(c + 1))) <= n)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;

    /* for (x = 0; x < max; x++) { */
    /*   cout << x + ((double)d / ((double)x + 1)) << endl; */
    /*   if (x + ((double)d / ((double)x + 1)) <= n) */
    /*     break; */
    /* } */
    /* cout << (x < max ? "YES" : "NO") << endl; */
  }
  return 0;
}
