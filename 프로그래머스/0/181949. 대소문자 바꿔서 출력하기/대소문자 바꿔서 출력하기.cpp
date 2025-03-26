#include <iostream>
#include <string>
#include <cctype> // isupper, tolower 등

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (char s : str) {
        if (isupper(s)) {
            cout << (char)tolower(s);
        } else {
            cout << (char)toupper(s);
        }
    }
    return 0;
}
