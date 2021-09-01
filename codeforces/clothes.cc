#include <iostream>
#include <limits>

using namespace std;
using ll = long long;

int prices[100];
bool match[100][100];

int main() {
  int n, m, a, b;
  cin >> n >> m;
  ll MAXVAL = numeric_limits<ll>::max(), minPrice = MAXVAL;

  for (int i = 0; i < n; i++)
    cin >> prices[i];
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    match[a - 1][b - 1] = match[b - 1][a - 1] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (match[i][j] && match[j][k] && match[k][i])
          minPrice = min(minPrice, ll(prices[i] + prices[j] + prices[k]));
      }
    }
  }

  cout << (minPrice == MAXVAL ? -1 : minPrice);
  return 0;
}
