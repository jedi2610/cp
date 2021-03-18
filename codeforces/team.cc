#include<iostream>

using namespace std;
using ll = long long;

int main() {

    int t, a, b, c, counter;
    cin >> t;
    counter = 0;

    while(t--) {

        cin >> a >> b >> c;
        if (a & b || a & c || b & c)
            counter++;
    }
    cout << counter;

}
