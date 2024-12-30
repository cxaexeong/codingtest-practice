#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,v,count = 0;
    cin >> n;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    
    cin >> v;
        
    for (int num:numbers){
        if (num == v){
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}