def solution(a, b, n):
    total_cola = 0  # 받은 콜라의 총 개수
    
    while n >= a:  # 교환이 가능한 동안 반복
        new_cola = (n // a) * b  # 교환으로 받는 새 콜라 병 수
        remain = n % a           # 교환 후 남는 빈 병
        total_cola += new_cola   # 받은 콜라 병 수를 누적
        n = new_cola + remain    # 새 병과 남은 병으로 다시 반복
        
    return total_cola
