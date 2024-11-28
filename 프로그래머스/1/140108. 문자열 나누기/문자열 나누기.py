def solution(s):
    same_count = 0
    diff_count = 0
    result = 0
    first_char = None

    for char in s:
        if first_char is None:  # 기준 문자 설정
            first_char = char

        if char == first_char:
            same_count += 1
        else:
            diff_count += 1

        if same_count == diff_count:  # 나눌 조건 충족
            result += 1
            same_count = 0
            diff_count = 0
            first_char = None  # 기준 문자 초기화

    # 남은 문자가 있을 경우 한 덩어리로 추가
    if same_count != 0 or diff_count != 0:
        result += 1

    return result
