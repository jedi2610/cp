#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int minDays, maxDays, x;
    x = n / 7;
    n = n % 7;

    if(n == 6)
        minDays = x * 2 + 1;
    else
        minDays = x * 2;

    maxDays = x * 2 + min(2,n);
    cout << minDays << " " << maxDays;
    return 0;
}
