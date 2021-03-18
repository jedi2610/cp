#include <algorithm>
#include<iostream>
#include<string>

using namespace std;
using ll = int64_t;


bool isMin(string s1, string s2) {

    for (int i=0; i<s1.length(); i++) {
        if (s1[i] == s2[i]) continue;
        if (s2[i] < s1[i])
            return true;
        else
            return false;
    }
    return false;
}

int main() {

    int n;
    string num;
    cin >> n;
    cin >> num;
    string minNum = num;

    // shifting
    for (int i=0; i<n; i++) {
        // adding
        int lastNum = num[n-1] - '0';
        int diff = 10 - lastNum;

        if (diff != 10) {
            for (int i=0; i<n; i++) {
                int c = (num[i] + diff - 48) % 10;
                num[i] = c + 48;
            }
        }
        num = num[n-1] + num.substr(0,n-1);
        if (isMin(minNum, num))
            minNum = num;
    }

    cout << minNum;

    return 0;
}
