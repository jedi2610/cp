#include<iostream>
#include<string>
#include<set>

using namespace std;
using ll = int64_t;

int main() {

    int t, ans = 0;
    set<string> s = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    cin >> t;
    while (t--) {
        string in;
        cin >> in;

        try {
            int age = stoi(in);
            if (age < 18)
                ans++;
        } catch (invalid_argument e) {
            if (s.find(in) != s.end())
                ans++;
        }
    }
    cout << ans;
    return 0;
}
