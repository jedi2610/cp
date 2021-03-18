#include<iostream>
#include<algorithm>

using namespace std;
 using ll = int64_t;

int main() {

    int n, sum = 0, sum1 = 0;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n);
    int i = n-1;
    for (; i>=0; i--) {
        sum -= arr[i];
        sum1 += arr[i];
        if (sum1 > sum)
            break;
    }

    cout << n - i;

    return 0;
}
