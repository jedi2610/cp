#include <iostream>

#define MAXVAL 100005

using namespace std;
using ll = int64_t;

int seen[MAXVAL] = {0};
int a, b, m, r0;

int func(int x) { return (a * x + b) % m; }

int main() {
  int ans = 0;
  cin >> a >> b >> m >> r0;
  int r = r0;

  while (!seen[r]) {
    seen[r] = ans++;
    r = func(r);
  }

  cout << ans - seen[r] << endl;
  return 0;
}
