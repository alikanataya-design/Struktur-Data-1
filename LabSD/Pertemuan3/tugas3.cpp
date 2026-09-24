#include <iostream>
#include <stack>
using namespace std;

int main() {
    string kata;
    stack<char> s;

    cout << "Masukkan kata : ";
    cin >> kata;

    for (char c : kata)
        s.push(c);

    cout << "Hasil: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}