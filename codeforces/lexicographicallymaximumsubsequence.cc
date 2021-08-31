#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  int len = s.length();
  char maxChar[len];
  maxChar[len - 1] = s[len - 1];

  for (int i = s.length() - 2; i >= 0; i--) {
    maxChar[i] = max(maxChar[i + 1], s[i]);
  }
  for (int i = 0; i < len; i++)
    if (s[i] == maxChar[i])
      cout << maxChar[i];

  return 0;
}
