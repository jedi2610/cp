#include <algorithm>
#include <iostream>

using namespace std;
using ll = int64_t;

int main() {
  int n, k, sum = 0;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  for (int i = 0; i < k; i++)
    sum += a[i];

  cout << sum;
  return 0;
}
