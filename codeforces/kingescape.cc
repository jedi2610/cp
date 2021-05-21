#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, qx, qy, bx, by, dx, dy;
/* up, right, down, left */
int DY[] = {-1, 0, 1, 0};
int DX[] = {0, 1, 0, -1};
vector<vector<int>> SEEN;

int dfs(int x, int y) {
  if (x == dx && y == dy)
    return 1;
  else if (x == qx || y == qy || abs(qx - x) == abs(qy - y))
    return 0;

  for (int dxx : DX) {
    for (int dyy : DY) {

      int newx = x + dxx, newy = y + dyy;
      if ((dxx == 0 && dyy == 0) || newx > n || newy > n || newx <= 0 ||
          newy <= 0)
        continue;
      if (SEEN[newx - 1][newy - 1] == 1)
        continue;

      SEEN[newx - 1][newy - 1] = 1;
      int ret = dfs(newx, newy);
      if (ret == 1)
        return ret;
    }
  }
  return 0;
}

int bfs() {

  int SEEN[n][n];
  deque<pair<int, int>> q;
  q.push_back(make_pair(bx, by));
  while (!q.empty()) {

    auto [x, y] = q.front();
    q.pop_front();

    if (x == dx && y == dy) {
      return 1;
    } else if (x == qx || y == qy || abs(qx - x) == abs(qy - y))
      continue;

    for (int dxx : DX) {
      for (int dyy : DY) {
        int newx = x + dxx, newy = y + dyy;
        if ((dxx == 0 && dyy == 0) || newx > n || newy > n || newx <= 0 ||
            newy <= 0)
          continue;
        if (SEEN[newx - 1][newy - 1] == 1)
          continue;
        SEEN[newx - 1][newy - 1] = 1;
        q.push_back(make_pair(newx, newy));
      }
    }
  }
  return 0;
}

int getQuad(int x, int y) {
  if (x < qx && y < qy)
    return 1;
  else if (x > qx && y < qy)
    return 2;
  else if (x < qx && y > qy)
    return 3;
  return 4;
}

/* https://codeforces.com/problemset/problem/1033/A */
int main() {
  cin >> n >> qx >> qy >> bx >> by >> dx >> dy;

  SEEN = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
  int ret;
  /* ret = bfs(); */
  /* ret = dfs(bx, by); */
  ret = getQuad(bx, by) == getQuad(dx, dy);
  cout << (ret ? "YES" : "NO") << endl;
}
