#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {

  int n, k;
  ll id;
  cin >> n >> k;
  vector<ll> ids(k, -1);

  for (int i = 0; i < n; i++) {
    cin >> id;
    if (find(ids.begin(), ids.end(), id) == ids.end()) {
      if (ids.size() >= k)
        ids.pop_back();
      ids.insert(ids.begin(), id);
    }
  }

  cout << min(static_cast<ll>(k - count(ids.begin(), ids.end(), -1)),
              static_cast<ll>(k))
       << endl;
  for (auto val : ids) {
    if (val == -1)
      break;
    cout << val << " ";
  }
  return 0;
}
