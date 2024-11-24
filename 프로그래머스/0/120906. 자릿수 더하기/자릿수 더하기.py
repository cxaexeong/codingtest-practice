def solution(n):
    # 숫자를 문자열로 변환하여 각 자릿수를 리스트로 변환, 정수로 변환 후 합산
    return sum(int(i) for i in str(n))