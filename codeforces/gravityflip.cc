#include<iostream>
#include<algorithm>

using namespace std;
using ll = int64_t;


int main() {

    int n;
    cin >> n;

    int arr[n], ans[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
