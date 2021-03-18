#include<iostream>
#include<string>

using namespace std;
using ll = int64_t;

int main() {

    string bal;
    ll ans;
    cin >> bal;

    if (bal[0] != '-')
        ans = stoi(bal);
    else {
        ll ans1, ans2;
        ans1 = stoi(bal.substr(0, bal.length() - 1));
        ans2 = stoi(bal.substr(0, bal.length() - 2) + bal[bal.length()-1]);
        if (ans1 > ans2)
            ans = ans1;
        else
            ans = ans2;
    }

    cout << ans;
    return 0;
}
