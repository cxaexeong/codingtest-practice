def solution(board, h, w):
    # 보드의 길이
    n = len(board)
    # 동일한 색상의 개수를 저장할 변수
    count = 0
    # 상하좌우 이동을 위한 변화량
    dh = [0, 1, -1, 0]
    dw = [1, 0, 0, -1]
    
    # 기준 색상
    target_color = board[h][w]
    
    # 상하좌우 탐색
    for i in range(4):
        h_check = h + dh[i]
        w_check = w + dw[i]
        # 유효한 범위인지 확인
        if 0 <= h_check < n and 0 <= w_check < n:
            # 동일한 색상인 경우 count 증가
            if board[h_check][w_check] == target_color:
                count += 1
                
    return count
