from collections import deque

def bfs(n,k):
    q = deque()
    v = [0] * 200001
    
    q.append(n)
    v[n] = 1    # 시작 위치를 방문 처리 (1로 설정)
    
    while q:
        c = q.popleft()
        
        if c == k:            # 현재 위치가 목표 위치라면 이동 횟수를 반환
            return v[c] - 1
        
        for x in (c-1, c+1, c*2):
            if 0 <= x < 200001 and v[x] == 0:
                q.append(x)
                v[x] = v[c] + 1  # 현재 위치에서 이동한 횟수를 설정
     
n, k = map(int, input().split())
v = [0] * 200001
ans = bfs(n,k)
print(ans)