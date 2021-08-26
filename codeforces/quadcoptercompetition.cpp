#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int x = abs(x2 - x1), y = abs(y2 - y1);
    x += (x == 0)? 2 : 1;
    y += (y == 0)? 2 : 1;
    cout << 2 * (x + y) << endl;
    return 0;
}
