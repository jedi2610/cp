#include<iostream>

using namespace std;

int main() {

    int n, t, ct = 0;
    string order, temp;
    cin >> n >> t;
    cin >> order;

    while (ct < t) {
        for (int i=0; i<order.length(); i++) {

            if (order[i] == 'B' && order[i+1] == 'G') {
                order[i] = 'G';
                order[i+1] = 'B';
                i++;
            }
        }

        if (temp == order)
            break;

        temp = order;
        ct++;
    }

    cout << order;

    return 0;
}
