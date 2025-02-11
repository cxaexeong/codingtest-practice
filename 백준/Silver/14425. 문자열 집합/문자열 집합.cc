#include <bits/stdc++.h>
using namespace std;

const int Root = 1;
int unused = 2;
const int mx = 10000 * 500 + 5;
bool chk[mx];
int nxt[mx][26];

int c2i (char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = Root;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = Root;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < mx; i++) {
        fill(nxt[i], nxt[i]+26, -1);
    }
    cin >> n >> m;
    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }
    
    int ans = 0;
    while (m--) {
        string s;
        cin >> s;
        ans += find(s);
    }
    cout << ans;    
}