#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
unordered_set<int> two_sums;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    nums.resize(n);
    
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    // 1. 정렬
    sort(nums.begin(), nums.end());
    
    // 2. 가능한 두 수의 합을 set에 저장
    for (int i = 0; i < n; i++) 
        for (int j = i; j < n; j++) {
            two_sums.insert(nums[i] + nums[j]);
        }
    
    // 3. (k - z) = x + y 
    int max_k = 0;
    for (int k = n-1; k >= 0; k--) 
        for (int z = 0; z < k; z++) {
            if (two_sums.count(nums[k] - nums[z])) {
                max_k = max(max_k, nums[k]);
            }
        }
    cout << max_k;
}