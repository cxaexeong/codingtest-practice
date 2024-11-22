def solution(price):
    # 조건문은 가장 높은 할인률부터 확인해야 함!!
    if price >= 500000:
        return int(price * 0.8)  # 500,000 이상: 20% 할인
    elif price >= 300000:
        return int(price * 0.9)  # 300,000 이상: 10% 할인
    elif price >= 100000:
        return int(price * 0.95) # 100,000 이상: 5% 할인
    else:
        return price  # 할인 없음