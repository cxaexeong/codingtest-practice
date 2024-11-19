from collections import deque
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
v = [[False]*m for _ in range(n)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y):
    q = deque([(x,y)])
    v[x][y] = True
    area = 1        # 그림의 넓이
    
    while q:
        ci, cj = q.popleft()
        
        for i in range(4):
            ni, nj = ci+dx[i], cj+dy[i]
            if 0 <= ni < n and 0 <= nj < m and not v[ni][nj] and arr[ni][nj] == 1:
                q.append((ni,nj))
                v[ni][nj] = True
                area += 1
    return area

num_of_pic = 0
max_area = 0

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1 and not v[i][j]:
            num_of_pic += 1
            max_area = max(max_area, bfs(i,j))
print(num_of_pic)
print(max_area)    