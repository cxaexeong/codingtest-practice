def solution(numlist, n):
    
    # 정렬 기준을 람다 함수를 이용해 정의
    return sorted(numlist, key=lambda x: (abs(x-n), -x))