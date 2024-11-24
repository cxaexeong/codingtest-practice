def solution(n):
    # n의 제곱근을 계산한 후, 정수로 변환하여 제곱
    if int(n**0.5) ** 2 == n:
        return 1
    else:
        return 2