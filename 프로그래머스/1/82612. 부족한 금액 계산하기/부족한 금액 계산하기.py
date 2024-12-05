def solution(price, money, count):
    # 놀이기구를 타는 총 비용 계산
    total_cost = sum(price * i for i in range(1,count+1))
    
    # 부족한 금액 계산 (부족하지 않으면 0 반환)
    return max(0, total_cost - money)
    
            