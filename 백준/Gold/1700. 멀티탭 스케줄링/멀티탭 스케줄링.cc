#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    
    vector<int> schedule(k);
    for (int i = 0; i < k; i++) 
        cin >> schedule[i];
    
    set<int> plug;
    int unplug = 0;
    
    for (int i = 0; i < k; i++) {
        int current_device = schedule[i];
        
        // 이미 꽂혀 있다면 넘어감
        if (plug.count(current_device)) continue;
        // 멀티탭에 빈자리 있으면 꽂음
        if (plug.size() < n) {
            plug.insert(current_device);
            continue;
        }
        // 가득 찾다면, 뺄 기기 찾음(나중에 사용되거나 사용되지 않을 수 있음)
        int device_to_remove = -1, tmp = -1;
        
        for (int device : plug) {
            int nxt = INT_MAX;
            for (int j = i + 1; j < k; j++) {
                if (schedule[j] == device) {
                    nxt = j;
                    break;
                }
            }
            if (nxt > tmp) {
                tmp = nxt;    // 나중에 사용될거기 때문에 저장
                device_to_remove = device;
            }
        }
        // 기기를 제거하고 새로운 기기 꽂기
        plug.erase(device_to_remove);
        plug.insert(current_device);
        unplug++;
    }
    cout << unplug << '\n';
    return 0;
}