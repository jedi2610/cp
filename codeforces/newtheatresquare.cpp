#include<iostream>

using namespace std;
using ll = long long;

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, m, x, y, cost = 0;
        cin >> n >> m >> x >> y;

        if (2*x < y)
            y = 2 * x;

        for (int i=0; i<n; i++) {
            string tiles;
            cin >> tiles;

            for (int j=0; j<m; j++) {
                if (tiles[j] == '.') {
                    if (j+1 < m && tiles[j+1] == '.') {
                        cost += y;
                        j++;
                    } else
                        cost += x;
                }
            }
        }

        cout << cost << endl;
    }
    return 0;
}
