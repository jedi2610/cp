#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using ll = int64_t;

int main() {
  string a, s;
  cin >> a >> s;
  int idx = 0;
  sort(s.begin(), s.end(), greater<char>());
  /* reverse(s.begin(), s.end()); */

  for (int i = 0; i < a.length(); i++) {
    if (idx == s.length())
      break;
    if ((int)a[i] - '0' < (int)s[idx] - 48) {
      a[i] = s[idx];
      idx++;
    }
  }
  cout << a << endl;
}
