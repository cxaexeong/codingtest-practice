def solution(money):
    # 주문 가능한 아이스 아메리카노 수량
    count = money // 5500
    # 잔돈
    change = money % 5500
    # 결과 반환
    return [count, change]
