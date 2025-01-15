#include <bits/stdc++.h>
using namespace std;

int n;
int paper[130][130];
int cnt[2]; // white, blue

bool check(int x, int y, int size) {
    int first = paper[x][y];
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != first) 
                return false;
        }
    return true;
}

void recursive(int x, int y, int size) {
    if (check(x,y,size)) {
        cnt[paper[x][y]]++;
        return;
    }
    
    int newsize = size / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) 
            recursive(x+i*newsize, y+j*newsize, newsize);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];
    
    recursive(0,0,n);
    
    for (int i = 0; i < 2; i++)
        cout << cnt[i] << '\n';
    return 0;
}