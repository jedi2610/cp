#include<iostream>
#include<set>

using namespace std;
using ll = int64_t;

int main() {

    ll t, n, temp;
    cin >> t;

    while (t--) {
        set<int> numbers;
        cin >> n;
        while(n--) {
            cin >> temp;
            numbers.insert(temp);
        }

        cout << numbers.size() << endl;
    }
}
