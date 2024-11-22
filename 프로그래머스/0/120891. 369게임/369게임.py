def solution(order):
    # 문자열로 변환 후 '3', '6', '9'의 개수를 각각 합산
    return sum(str(order).count(ch) for ch in "369")