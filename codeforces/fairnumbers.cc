#include<iostream>
#include<string>
#include<set>

using namespace std;
using ll = long long;

bool check(string num, int digit) {

    switch(digit) {
        case 1:
            return true;
        case 2: {
            if ((num.back() - '0') % 2)
                return false;
            return true;
        }
        case 3: {
            int sum = 0;
            for (char c: num) {
                sum += (c - '0');
            }
            if (sum % 3)
                return false;
            return true;
        }
        case 4: {
            string s;
            if (num.length() > 2)
                s = num.substr(num.length()-2, num.length()-1);
            else
                s = num;
            int lastTwo = stoi(s);
            if (lastTwo % 4)
                return false;
            return true;
        }
        case 5: {
            if (num.back() == '0' || num.back() == '5')
                return true;
            return false;
        }
        case 6: {
            bool ans = check(num, 2) && check(num, 3);
            return ans;
        }
        case 7: {
            int a[] = {1, 3, 2, 6, 4, 5, 1, 3, 2, 6, 4, 5, 1, 3, 2, 6, 4, 5}, sum = 0, i = 0;
            for (char c: a) {
                sum += (c - '0') * a[i];
                i++;
            }
            if (sum % 7)
                return false;
            return true;
        }
        case 8: {
            string s;
            if (num.length() > 3)
                s = num.substr(num.length()-3, num.length()-1);
            else
                s = num;
            int lastThree = stoi(s);
            if (lastThree % 4)
                return false;
            return true;
        }
        case 9: {
            int sum = 0;
            for (char c: num) {
                sum += (c - '0');
            }
            if (sum % 9)
                return false;
            return true;
        }
        default:
            return false;
    }
}


bool solve(ll n) {

    ll num = n;
    while(num != 0) {
        int x = num % 10;
        if (x != 0 && (n%x) != 0)
            return false;
        num /= 10;
    }
    return true;
}


int main() {
   
    int t;
    cin >> t;
    while (t--) {
        ll n;
        set<int> digits;
        cin >> n;
        while(!solve(n))
            n++;
        cout << n << endl;
    }
    return 0;
}
