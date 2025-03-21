#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int target, int depth, int sum, int& count) {
    if (depth == numbers.size()) {
        if (sum == target) count++;
            return;
    }
    // 현재 숫자를 더하는 경우
    dfs(numbers, target, depth + 1, sum + numbers[depth], count);
    
    // 현재 숫자를 빼는 경우
    dfs(numbers, target, depth + 1, sum - numbers[depth], count);
}

int solution(vector<int> numbers, int target) {
    int count = 0;
    dfs(numbers, target, 0, 0, count);
    return count;
}