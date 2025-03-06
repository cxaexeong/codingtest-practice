#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    unordered_map<int,int> right;
    unordered_set<int> left;
    int count = 0;
    
    for (int t : topping) {
        right[t]++;
    }
    
    for (int t : topping) {
        left.insert(t);
        right[t]--;
        
        if (right[t] == 0) {
            right.erase(t);
        }
        
        if (left.size() == right.size()) {
            count++;
        }
    }
    return count;
}