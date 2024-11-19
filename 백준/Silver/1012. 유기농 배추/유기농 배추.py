import sys
sys.setrecursionlimit(10000)
input_line = sys.stdin.readline

def dfs(x, y):
    # 방향 벡터 정의
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]

    # 현재 노드를 방문 처리
    graph[y][x] = -1

    # 주변 노드 탐색
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        # 주변 노드가 그래프 범위 내에 있는지, 미방문 노드인지 확인
        if 0 <= nx < m and 0 <= ny < n and graph[ny][nx] == 1:
            dfs(nx, ny)  # 재귀적으로 탐색


t = int(input_line())
for _ in range(t):
    m,n,k = map(int, input_line().split())
    graph = [[0]*m for _ in range(n)]
    for _ in range(k):
        x,y = map(int, input_line().split())
        graph[y][x] = 1
    count = 0
    for a in range(m):
        for b in range(n):
            if graph[b][a] == 1:
                dfs(a,b)
                count += 1
    print(count)            
