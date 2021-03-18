#include <cstdint>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>

using namespace std;
using ll = int64_t;

vector<ll> DP;

ll findFactorial(int n) {

    if (n == 0 || n == 1)
        return 1;
    if (DP[n-1] > 1)
        return DP[n-1];

    ll ans = n * findFactorial(n-1);
    DP[n-1] = ans;
    return ans;
}

int main() {

    string word;
    map<char, int> noOfLetters;
    cin >> word;

    sort(word.begin(), word.end());
    DP = vector<ll>(word.length(), -1);

    for (char c: word)
        noOfLetters[c]++;
        
    ll total = findFactorial(word.length());

    for (auto c: noOfLetters) {
       
        if (c.second == 1)
            continue;
        total /= DP[c.second-1];
    }

    cout << total << endl;
    do{
        cout << word << endl;
    } while (next_permutation(word.begin(), word.end()));


    return 0;
}
