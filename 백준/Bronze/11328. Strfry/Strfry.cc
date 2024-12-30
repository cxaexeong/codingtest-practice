#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    while (n--){
        string a,b;
        cin >> a >> b;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        if (a==b){
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    
    return 0;
}