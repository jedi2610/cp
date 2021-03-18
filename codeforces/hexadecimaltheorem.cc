#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
using ll = long long;

vector<ll> DP;

void fibo(ll n) {

    ll t1 = 0, t2 = 1, ans = 1, i = 2;
    DP[0] = 0;
    DP[1] = 1;
    while(ans <= n) {
        DP[i] = ans;
        t1 = t2;
        t2 = ans;
        ans = t1 + t2;
        i++;
    }
}

int main() {

    ll n;
    cin >> n;
    int index = round(2.078087 * log(n) + 1.672276);
    DP = vector<ll>(10000);
    fibo(n);
    if (n == 0) {
        cout << "0 0 0";
    } else if (n == 1) {
        cout << "0 0 1";
    } else if (n == 2) {
        cout << "0 1 1";
    } else {
        cout << DP[index-4] << " ";
        cout << DP[index-3] << " ";
        cout << DP[index-1] << endl;
    }
    return 0;
}
