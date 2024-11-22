def solution(my_string):
    # 모든 문자열을 소문자로 변환
    lower_text = my_string.lower()
    # 정렬된 문자열 생성 => ''.join():문자열 변환
    sorted_text = ''.join(sorted(lower_text))
    return sorted_text