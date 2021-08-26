#include <iostream>
#include <math.h>

using namespace std;
using ll = int64_t;

ll n;

ll calc(ll a[], ll sum, ll i) {
  if (i < 0)
    return 0;

  sum += (calc(a, sum, i - 1) + a[i]);

  double l2 = log2((double)n - i);
  if (l2 == floor(l2))
    l2--;
  ll rem = pow(2, (ll)l2);
  a[i + rem] += a[i];

  cout << sum << endl;
  return sum;
}

/* https://codeforces.com/contest/178/submission/3169457 */
/* a much better solution. my solution is a little slow, relatively,
 * because i do a lot of log2 and pow calculations which is expensive. */
int main() {

  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  calc(a, 0, n - 2);

  return 0;
}
