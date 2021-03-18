#include <cstdint>
#include<iostream>

using namespace std;
using ll = int64_t;

ll findDifference(ll weights[], int i, ll sumSet1, ll sumTotal) {
   
    if (i == 0)
        return abs((sumTotal - sumSet1) - sumSet1);

    // greedy algorithm
    // you either add it to set 1 or you don't
    return min(findDifference(weights, i-1, sumSet1 + weights[i], sumTotal), findDifference(weights, i-1, sumSet1, sumTotal));

}

int main() {

    int n;
    cin >> n;
    ll weights[n], sumTotal = 0;

    for (int i=0; i<n; i++) {
        cin >> weights[i];
        sumTotal += weights[i];
    }

    ll diff = findDifference(weights, n-1, 0, sumTotal);
    cout << diff;
    return 0;
}
