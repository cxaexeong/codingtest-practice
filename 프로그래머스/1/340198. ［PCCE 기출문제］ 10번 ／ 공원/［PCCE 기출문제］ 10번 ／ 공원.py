def solution(mats, park):
    rows, cols = len(park), len(park[0])
    mats.sort(reverse=True)  # 큰 크기의 돗자리부터 확인
    
    def can_place_mat(x, y, size):
        # size x size 돗자리를 (x, y) 위치에서 놓을 수 있는지 확인
        if x + size > rows or y + size > cols:
            return False
        for i in range(x, x + size):
            for j in range(y, y + size):
                if park[i][j] != "-1":  # 사람이 있는 곳이면 놓을 수 없음
                    return False
        return True
    
    # 가장 큰 돗자리부터 놓아보기
    for mat_size in mats:
        for i in range(rows):
            for j in range(cols):
                if can_place_mat(i, j, mat_size):
                    return mat_size  # 가장 큰 돗자리 크기 반환
    return -1  # 아무 돗자리도 놓을 수 없는 경우