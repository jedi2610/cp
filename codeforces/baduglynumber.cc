#include <iostream>

using namespace std;
using ll = long long;

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1)
      cout << "-1" << endl;
    else
      cout << "2" << string(n - 1, '7') << endl;
  }
  return 0;
}
