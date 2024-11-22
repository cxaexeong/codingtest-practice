import math

def solution(n):
    # 피자 판 수 계산 (7조각으로 나누고 올림 처리)
    return math.ceil(n / 7)