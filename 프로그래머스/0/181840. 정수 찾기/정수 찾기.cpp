#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    for (int lst : num_list) {
        if (lst == n)
            return 1;
    }
    return 0;
}