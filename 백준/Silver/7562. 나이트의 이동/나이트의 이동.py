from collections import deque

# 나이트의 이동 방향
dx = [-2, -2, -1, -1, 1, 1, 2, 2]
dy = [-1, 1, -2, 2, -2, 2, -1, 1]

def bfs(si,sj,ei,ej):
    q = deque([(si,sj,0)]) # (x, y, 이동횟수)
    v[si][sj] = True
    
    while q:
        cx, cy, count = q.popleft()
        
        # 목표 위치에 도달하면 이동 횟수 반환
        if cx == ei and cy == ej:
            return count
        
        for d in range(8):
            nx, ny = cx + dx[d], cy + dy[d]
            if 0 <= nx < l and 0 <= ny < l and not v[nx][ny]:
                q.append((nx,ny, count + 1))
                v[nx][ny] = True         
            
tc = int(input())
for _ in range(tc):
    l = int(input())
    v = [[False] * l for _ in range(l)]
    si, sj = map(int, input().split())
    ei, ej = map(int, input().split())
    
    # BFS 실행
    ans = bfs(si,sj,ei,ej)
    print(ans)
