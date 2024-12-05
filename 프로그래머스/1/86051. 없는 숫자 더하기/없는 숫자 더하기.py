def solution(numbers):
    # 0부터 9까지의 모든 숫자의 합은 45
    total = sum(range(10))
    # 배열에 포함된 숫자의 합을 뺀다
    return total - sum(numbers)

    