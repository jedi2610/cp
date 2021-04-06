#include <iostream>

using namespace std;
using ll = long long;

int main() {

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int i = s.rfind("00");
    int j = s.find("11");
    cout << (i != -1 && j != -1 && j < i ? "NO" : "YES") << endl;
  }
  return 0;
}
