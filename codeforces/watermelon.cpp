#include<iostream>

using namespace std;
using ll = long long;

int main() {

    int w;
    cin >> w;

    if (w%2 == 0 && w > 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
