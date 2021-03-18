#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
using ll = long long;

void displayOdd(ll arr[], ll n) {
    
    ll mid = floor(n/2);
    ll start = 0;
    ll end = mid+1;

    for(ll i=0; i<n; i++) {
        if (i%2==0) {
            cout << arr[start] << " ";
            start++;
        }
        else {
            cout << arr[end] << " ";
            end++;
        }
    }
}

void displayEven(ll arr[], ll n) {
   
    ll mid = floor(n/2);
    ll start = mid - 1;
    ll end = n-1;

    for(int i=0; i<n; i++) {
        if (i%2==0) {
            cout << arr[start] << " ";
            start--;
        }
        else {
            cout << arr[end] << " ";
            end--;
        }
    }
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    ll arr[n];
    for(ll i=0; i<=n; i++)
        arr[i] = i+1;

    ll size = sizeof(arr)/sizeof(arr[1]);
    if(n%2 == 0)
        displayEven(arr, size);
    else
        displayOdd(arr, size);
 

    return 0;
}
