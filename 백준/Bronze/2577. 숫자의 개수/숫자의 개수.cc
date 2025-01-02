#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    
    int total = a*b*c;
    int arr[10] = {0};
    
    string totalstr = to_string(total);
    
    for (char digit : totalstr){
        arr[digit - '0']  += 1;
    }
    
    for (int count : arr){
        cout << count << endl;
    }
    return 0;
}