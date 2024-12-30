#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,x,count = 0;
    cin >> n;
    vector<int> arr(n); // arr = [0,0,,,,n]
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> x;
    
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    
    while (left < right){
        int sum = arr[left] + arr[right];
        if (sum == x) {
            count++;
            left++;
            right--;
        } else if (sum < x){
            left++;
        } else if (sum > x){
            right--;
        }
    }
    
    cout << count << endl;
    return 0;
}
