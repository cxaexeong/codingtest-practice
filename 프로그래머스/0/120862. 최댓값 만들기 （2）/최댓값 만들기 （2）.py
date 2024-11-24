def solution(numbers):
    # 배열 정렬
    numbers.sort()
    
    # 두 가지 경우 비교 (음수*음수, 양수*양수)
    max_result = max(numbers[0] * numbers[1], numbers[-1] * numbers[-2])
    
    return max_result