#include <iostream>
#include <math.h>

using namespace std;
using ll = int64_t;

int main() {
  int k, a, b, v, count = 0;
  cin >> k >> a >> b >> v;

  while (a > 0) {
    a -= min(k, b + 1) * v;
    b -= min(k - 1, b);
    count++;
  }
  cout << count << endl;
}
