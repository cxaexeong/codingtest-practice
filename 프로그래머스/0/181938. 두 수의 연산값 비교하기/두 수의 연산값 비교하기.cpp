#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int ab = stoi(to_string(a) + to_string(b));
    int ab_2 = 2 * a * b;
    return ab >= ab_2? ab : ab_2; 
}