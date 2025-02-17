#include <iostream>
#include <vector>

using namespace std;

const int OFFSET = 1000000; // To shift negative numbers
const int SIZE = 2000001;   // Range from -1,000,000 to 1,000,000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    vector<int> count(SIZE, 0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        count[num + OFFSET]++;
    }

    for (int i = 0; i < SIZE; i++) {
        while (count[i]--) {
            cout << (i - OFFSET) << '\n';
        }
    }

    return 0;
}
