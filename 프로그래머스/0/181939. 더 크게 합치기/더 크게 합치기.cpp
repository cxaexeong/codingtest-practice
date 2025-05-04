#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int ab = stoi(to_string(a) + to_string(b));
    int ba = stoi(to_string(b) + to_string(a));
    return ab >= ba ? ab : ba;
}