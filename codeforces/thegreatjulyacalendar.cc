#include <iostream>

using namespace std;
using ll = int64_t;

int find(ll n) {

  int maxNum = 0;
  while (n > 0) {
    maxNum = max(maxNum, (int)(n % 10));
    n /= 10;
  }
  return maxNum;
}

int main() {

  ll n, count = 0;
  cin >> n;
  while (n > 0) {
    int ans = find(n);
    n -= ans;
    count++;
  }

  cout << count << endl;
  return 0;
}
