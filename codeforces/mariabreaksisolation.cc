/* code by `minato` from the leaderboard */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using u64 = uint_fast64_t;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
constexpr char ln = '\n';
constexpr long long MOD = 1000000007;
// constexpr long long MOD = 998244353;
template <class T1, class T2> inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T1, class T2> inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
inline int popcount(int x) { return __builtin_popcount(x); }
inline int popcount(long long x) { return __builtin_popcountll(x); }
void print() { cout << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &...args) {
  cout << x << " ";
  print(args...);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  rep(i, N) cin >> A[i];

  sort(all(A));
  for (int i = N; i >= 0; i--) {
    if (i >= A[i]) {
      cout << i + 1 << ln;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;
  cin >> Q;
  while (Q--) {
    solve();
  }
}
