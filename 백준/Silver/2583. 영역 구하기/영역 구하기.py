from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]

m, n, k = map(int, input().split())
v = [[0] * n for _ in range(m)] # 색칠된 영역 표시

# 직사각형 색칠
for _ in range(k):
    sx, sy, ex, ey = map(int, input().split())
    for i in range(sy,ey):
        for j in range(sx,ex):
            v[i][j] = 1
    
def bfs(x,y):
    q = deque([(x,y)])
    v[x][y] = 1 # 방문 표시 및 색칠된 영역으로 간주 
    area = 1    # 현재 영역 크기 초기화
    
    while q:
        cx, cy = q.popleft()
        #if cx == ex and cy == ey:
        #    return area 
        
        for d in range(4):
            nx, ny = cx + dx[d], cy + dy[d]
            if 0 <= nx < m and 0 <= ny < n and v[nx][ny] == 0:
                q.append((nx,ny))
                v[nx][ny] = 1
                area += 1
    return area           

# 영역 구하기
areas = []
for i in range(m):
    for j in range(n):
        if v[i][j] == 0:
            areas.append(bfs(i,j))

# 결과 출력
areas.sort()
print(len(areas))
print(' '.join(map(str,areas)))