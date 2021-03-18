#include<iostream>
#include<cmath>

using namespace std;
using ll = int64_t;

int main() {

    int t;
    cin >> t;

    ll hp, n, m;
    while (t--) {
        // n = void absorption, m = lightning strike
        cin >> hp >> n >> m;
        while (n-- && hp > 0) {
            if (hp <= 10 && m > 0)
                break;
            else if (hp <= 20 && m > 1)
                break;
            hp = round(hp/2);
            hp += 10;
        }
        hp -= (m * 10);
        if (hp <= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
