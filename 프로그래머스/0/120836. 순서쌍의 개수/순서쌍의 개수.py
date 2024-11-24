def solution(n):
    count = 0
    for i in range(1, n + 1):
        if n % i == 0:  # i가 n의 약수인지 확인
            count += 1  # 약수일 경우 카운트 증가
    return count
