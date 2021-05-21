#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/955/A */
int main() {

  int hh, mm;
  float hunger, upHunger, cost, decHunger, mins = 0;
  cin >> hh >> mm;
  cin >> hunger >> upHunger >> cost >> decHunger;
  if (mm == 0)
    mm = 60;
  else
    hh++;

  if (hh <= 20)
    mins = (60 * (20 - hh)) + (60 - mm);

  float moreHunger = hunger + (mins * upHunger), newCost = (4.0 * cost) / 5.0;
  float newTotal = ceil(moreHunger / decHunger) * newCost,
        total = ceil(hunger / decHunger) * cost;

  if (hh <= 20)
    cout << (newTotal < total ? newTotal : total);
  else
    cout << newTotal;

  return 0;
}
