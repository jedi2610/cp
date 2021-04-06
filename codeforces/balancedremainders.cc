#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {

  int t, n, x;
  int cost[3][3] = {{0, 1, 2},  /* cost from 0 to other nums */
                    {2, 0, 1},  /* cost from 1 to other nums */
                    {1, 2, 0}}; /* cost from 2 to other nums */
  cin >> t;
  while (t--) {
    cin >> n;
    int equi = n / 3, moves = 0;
    int spare[3] = {-equi, -equi, -equi};
    for (int i = 0; i < n; i++) {
      cin >> x;
      spare[x % 3]++;
    }

    int cur = distance(begin(spare), max_element(begin(spare), end(spare)));
    for (int i = 0; i < 3; i++)
      if (spare[i] < 0) {
        while (spare[i] != 0) {
          int prev = spare[i];
          moves += (cost[cur][i]) *
                   (-spare[i] > spare[cur] ? spare[cur] : -spare[i]);
          spare[i] += (-spare[i] > spare[cur] ? spare[cur] : -spare[i]);
          spare[cur] -= -prev - -spare[i];
          cur = distance(begin(spare), max_element(begin(spare), end(spare)));
        }
      }

    cout << moves << endl;
  }

  return 0;
}
