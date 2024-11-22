def solution(num, k):
    # num이 정수형이면 for문에서 in이 작동x, 문자열 변환 필요
    num_str = str(num)
    # k를 문자열로 변환하여 위치 찾기
    index = num_str.find(str(k))
    # 0부터 시작하는 index를 1부터 시작하도록 수정
    return index + 1 if index != -1 else -1