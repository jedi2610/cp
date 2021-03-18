#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m, rows= 0, cols = 0, mm, x;
        cin >> n >> m;
        bool row[n], col[m];
        fill(row, row+n, true);
        fill(col, col+m, true);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> x;
                if (x)
                    row[i] = col[j] = false;
            }
        }

        for (int i=0; i<n; i++) {
            if (row[i])
                rows++;
        }
        
        for (int i=0; i<m; i++) {
            if (col[i])
                cols++;
        }

        mm = min(rows, cols);
        cout << (mm % 2? "Ashish": "Vivek") << endl;
    }
    return 0;
}
