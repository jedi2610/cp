#include <cstdint>
#include<iostream>
#include<string>

using namespace std;
using ll = int64_t;

int main() {

    string board[8];
    for (int i=0; i<8; i++)
        cin >> board[i];

    for (int i=0; i<8; i++)
        cout << board[i] << endl;

    return 0;
}
