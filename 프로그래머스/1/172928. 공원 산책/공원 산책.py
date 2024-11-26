def solution(park, routes):
    # 공원의 크기
    rows, cols = len(park), len(park[0])
    
    # 방향에 따른 이동 좌표 변화량
    direction_map = {
        "N": (-1, 0),  # 북쪽으로 한 칸 이동
        "S": (1, 0),   # 남쪽으로 한 칸 이동
        "W": (0, -1),  # 서쪽으로 한 칸 이동
        "E": (0, 1)    # 동쪽으로 한 칸 이동
    }
    
    # 시작 위치 찾기
    for r in range(rows):
        for c in range(cols):
            if park[r][c] == "S":
                position = [r, c]
                break

    # 명령 처리
    for route in routes:
        direction, distance = route.split()
        distance = int(distance)
        dr, dc = direction_map[direction]
        
        # 이동 가능한지 미리 확인
        nr, nc = position[0], position[1]
        is_valid = True
        for _ in range(distance):
            nr += dr
            nc += dc
            if not (0 <= nr < rows and 0 <= nc < cols) or park[nr][nc] == "X":
                is_valid = False
                break
        
        # 유효한 경우 위치 업데이트
        if is_valid:
            position = [nr, nc]

    return position
