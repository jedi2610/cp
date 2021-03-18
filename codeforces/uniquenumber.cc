#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;
    int max = (9 * 10) / 2;
    while (t--) {
        int x, ans = 0;
        cin >> x;

        if (x < 10) {
            cout << x << endl;
            continue;
        }
        if (x > max) {
            cout << "-1" << endl;
            continue; }

        string num = "";
        for (int i=9; i>0; i--) {
            if (ans+i <= x) {
                ans += i;
                num.append(to_string(i));
                if (ans == x) {
                    break;
                }
            }
        }
        sort(num.begin(), num.end());
        cout << num << endl;
    }
    return 0;
}
