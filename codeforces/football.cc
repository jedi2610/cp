#include<iostream>
#include<string>

using namespace std;
using ll = int64_t;

int main() {

    string order;
    cin >> order;

    ll ct = 1;
    char prevChar = '1';
    bool danger = false;

    if (order.find("0000000") != string::npos || order.find("1111111") != string::npos)
        danger = true;

    if (danger)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
