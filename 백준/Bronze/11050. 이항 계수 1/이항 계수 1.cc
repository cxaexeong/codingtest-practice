#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    int ret = 1;
    for(int i = 1; i <= n; i++) ret *= i;    // ret = n!
    for(int i = 1; i <= k; i++) ret /= i;    // ret = n! / k!
    for(int i = 1; i <= n-k; i++) ret /= i;  // ret= n! / (k! * (n-k)!)
    cout << ret;
} 