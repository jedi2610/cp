#include <iostream>
#include <set>
#include <string>

using namespace std;
using ll = int64_t;

int main() {

  string s;
  cin >> s;
  ll ans = 1;
  int pos = 10;
  set<char> chars;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    if (c >= 'A' && c <= 'J' && chars.find(c) == chars.end()) {
      pos = (i == 0) ? 9 : pos;
      ans = (i == 0) ? pos : ans *= pos;
      pos -= (i == 0) ? 0 : 1;
      chars.insert(c);
    } else if (c == '?') {
      ans = (i == 0) ? 9 : ans * 10;
    }
  }
  cout << ans;

  return 0;
}
