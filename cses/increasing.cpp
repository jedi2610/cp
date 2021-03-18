#include<iostream>

using namespace std;
using ll = long long;

int main(int argc, char *argv[])
{
    ll n, turns=0;
    cin >> n;
    ll arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=1; i<n; i++) {
        if(arr[i] <= arr[i-1]) {
            ll offset = arr[i-1] - arr[i];
            arr[i] += offset;
            turns += offset;
        }
    }

    cout << turns;
    return 0;
}
