#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        ll yPos = y.find('1');
        ll xPos = x.find('1', yPos);
        cout << xPos - yPos << endl;
    }
    return 0;
}
