#include<iostream>
#include<string>
#include<map>

using namespace std;
using  ll = long long;

int main() {

    string word;
    cin >> word;
    map<char, string> data;

    for (char c: word) {
        if (data.count(c))
            data[c] += c;
        else
            data[c] = c;
    }

    string mid = "", first = "", last = "", temp = "";
    for (auto c: data) {
        if (c.second.length() % 2 == 1 && mid != "") {
            cout << "NO SOLUTION";
            return 0;
        }
        else if (c.second.length() % 2 == 1)
            mid = c.second;
        else {
            temp = c.second.substr(0, c.second.length()/2);
            first = temp + first;
            last += temp;
        }
    }

    cout << first << mid << last;
    return 0;
}
