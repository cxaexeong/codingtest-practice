from collections import Counter

def solution(X, Y):
    # 각 숫자의 등장 횟수를 계산
    count_x = Counter(X)
    count_y = Counter(Y)
    
    # 공통된 숫자의 최소 등장 횟수를 저장
    result = []
    for digit in count_x:
        if digit in count_y:
            result.append(digit * min(count_x[digit], count_y[digit]))
    
    # 결과를 내림차순으로 정렬
    result = ''.join(sorted(result, reverse=True))
    
    # 결과가 없으면 -1 반환
    if not result:
        return "-1"
    # 결과가 0으로만 이루어져 있으면 0 반환
    if result[0] == '0':
        return '0'
    
    return result