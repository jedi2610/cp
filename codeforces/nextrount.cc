#include <cstdint>
#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int n, k, ct, val;
    cin >> n >> k;
    int score[n];

    for (int i=0; i<n; i++) {
        cin >> score[i];
    }

    val = score[k-1];
    ct = 0;
    for (int i=0; i<n; i++) {
        if (score[i] >= val && score[i] != 0)
            ct++;
    }
    cout << ct;
    return 0;
}
