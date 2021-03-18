#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
using ll = long long;

ll findSubStr(string str1, string str2) {

    ll s1 = str1.size(), s2 = str2.size();
    while(s1 >= 0 && s2 >= 0) {
        if (str1[s1] == str2[s2]) {
            s1--;
            s2--;
        } else {
            break;
        }
    }

    s1++; s2++;
    return s1 + s2;
}


int main() {

    string str1, str2;
    cin >> str1 >> str2;
    ll ans = 0;
    ans = findSubStr(str1, str2);
    cout << ans;
    return 0;
}
