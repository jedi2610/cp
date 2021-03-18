#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int n;
    cin >> n;
    if (n % 2)
        cout << "0" << endl;
    else
        cout << (1 << (n >> 1));  // dividing n by 2 and then raising it to the power of 2 (using 1 as i'm doing bit operations)
    return 0;
}
