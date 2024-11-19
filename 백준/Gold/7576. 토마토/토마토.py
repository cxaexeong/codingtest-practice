from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs():
    q = deque([(x,y) for x in range(n) for y in range(m) if tomato[x][y] == 1])
    
    while q:
        cx, cy = q.popleft()
        
        for d in range(4):
            nx, ny = cx + dx[d], cy + dy[d]
            if 0 <= nx < n and 0 <= ny < m and tomato[nx][ny] == 0:
                q.append((nx,ny))
                tomato[nx][ny] = tomato[cx][cy] + 1     

m, n = map(int, input().split())
tomato = [list(map(int, input().split())) for _ in range(n)]
# v = [[False] * n for _ in range(m)]

bfs()

# 모든 토마토가 익었는지 확인하고, 최대 일수 계산하면 그 값이 최소한의 총 일수
max_days = 0
for row in tomato:
    if 0 in row:
        print(-1)
        break
    max_days = max(max_days,max(row))
else:
    print(max_days - 1) # 첫 날(1)을 제외한 결과 