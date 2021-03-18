#include<iostream>

using namespace std;
using ll = int64_t;

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    int minDiff = 10000;
    for (int i=1; i<n-1; i++) {
        int maxDiff = 0;
        for (int j=0; j<n-1; j++) {

            if (j == i)
                continue;

            if (j+1 == i)
                maxDiff = max(maxDiff, (a[j+2] - a[j]));
            else
                maxDiff = max(maxDiff, (a[j+1] - a[j]));
        }
        minDiff = min(minDiff, maxDiff);
    }
    cout << minDiff << endl;

    return 0;
}
