#include<iostream>
#include<vector>

using namespace std;
using ll = int64_t;

int main() {

    int n, s1 = 0, s2 = 0;
    int turn=0, begin, last;
    cin >> n;
    vector<int> values(n);

    for(int i=0; i<n; i++)
        cin >> values[i];

    while(n--) {
        begin = values.front();
        last = values.back();
        if (turn) {

            if (begin > last) {
                s2 += begin;
                values.erase(values.begin());
            } else {
                s2 += last;
                values.pop_back();
            }
            turn = 0;
        } else {

            if (begin > last) {
                s1 += begin;
                values.erase(values.begin());
            } else {
                s1 += last;
                values.pop_back();
            }
            turn = 1;
        }
    }

    cout << s1 << " " << s2 << endl;
}
