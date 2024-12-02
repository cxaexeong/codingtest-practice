def solution(food):
    left_side = []
    
    # 왼쪽 배열 구성
    for i in range(1, len(food)):
        count = food[i] // 2
        left_side.extend([str(i)] * count)
        
    # 오른쪽 배열은 왼쪽 배열의 역순
    right_side = left_side[::-1]
    
    # 가운데 물("0") 추가
    return ''.join(left_side) + '0' + ''.join(right_side)
        