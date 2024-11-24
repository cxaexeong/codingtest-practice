def solution(my_string):
    # 문자열에서 숫자만 추출하고 정수로 변환
    numbers = [int(char) for char in my_string if char.isdigit()]
    # 오름차순 정렬
    numbers.sort()
    return numbers