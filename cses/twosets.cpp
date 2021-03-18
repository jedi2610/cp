#include<iostream>
#include <iterator>
#include<vector>

using namespace std;
using ll = long long;


ll getSum(ll n) {
    return (n * (n-1))/2;
}

void display(vector<ll> vec) {

    vector<ll>::iterator itr;
    cout << vec.size() << endl;
    for (itr = vec.begin(); itr != vec.end(); ++itr)
        cout << *itr << " ";
}

void findTwoSets(ll num, ll goal) {
    
    vector<ll> s1, s2;

    // for even numbers the goal reaches 0 first but then 
    // num doensn't reach 0 which makes the sum of all elements
    // of 2nd vector(s2) < sum of all elements of 1st vector (s1)
    // so we make the while condition to goal || num
    while (goal || num) {
        if (goal - num >= 0) {
            s1.push_back(num);
            goal -= num;
        } else {
            s2.push_back(num);
        }
        num--;
    }

    display(s1);
    cout << endl;
    display(s2);
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    ll sum = getSum(n+1);
    
    if (sum % 2 != 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    ll goal = sum/2;
    findTwoSets(n, goal);

    return 0;
}
