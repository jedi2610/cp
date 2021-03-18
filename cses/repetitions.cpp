#include<iostream>
#include <string>

using namespace std;
using ll = long long; 

int main(int argc, char *argv[])
{
    string dna;
    cin >> dna;

    long currentLength = 1, maxLength = 1;
    char prev = ' ';
    
    for (int i=0; i<=dna.length(); i++) {
        if (prev == dna[i]) {
            currentLength++;
        } else {
            maxLength = std::max(maxLength, currentLength);
            currentLength = 1;
        }
        prev = dna[i];
    }

    cout << maxLength;
    return 0;
}
