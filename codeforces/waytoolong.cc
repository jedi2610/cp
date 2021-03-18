#include<iostream>
#include<string>

using namespace std;
using ll = long long;

void checkWord(string word) {

    int length = word.length();
    if (length <= 10) {
        cout << word << endl;
        return;
    }

    cout << word[0] << length - 2 << word[length-1] << endl;
}


int main() {

    int t;
    string word;

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> word;
        checkWord(word);
    }
    return 0;
}
