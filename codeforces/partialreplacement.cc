#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1506/B */
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, count = 0;
    string s;
    cin >> n >> k;
    cin >> s;
    int first = s.find('*');
    int last = s.find_last_of('*');
    /* cout << first << " " << last << endl; */
    for (int i = first; i < last; i++) {
      /* cout << "i bef: " << i << endl; */
      i = s.find_last_of('*', i + k) - 1;
      /* cout << "i: " << i << endl; */
      count++;
    }
    cout << count + 1 << endl;
  }
  return 0;
  /* 8 3 */
  /* *****..* */
}
