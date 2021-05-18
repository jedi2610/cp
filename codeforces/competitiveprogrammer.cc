#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1266/A */
int main() {

  int t;
  cin >> t;
  while (t--) {
    string s;
    int sum = 0, numEven = 0, numZero = 0;
    cin >> s;
    for (char c : s) {
      int num = (int)(c - '0');
      sum += num;
      if (num == 0)
        numZero++;
      if (num % 2 == 0)
        numEven++;
    }
    if (numZero >= 1 && numEven >= 2 && sum % 3 == 0)
      cout << "red";
    else
      cout << "cyan";
    cout << endl;
  }
  return 0;
}
