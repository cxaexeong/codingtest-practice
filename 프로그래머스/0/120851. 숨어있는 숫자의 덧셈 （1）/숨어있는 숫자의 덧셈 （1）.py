def solution(my_string):
    # 숫자인 경우 정수로 변환하여 리스트에 추가
    result = [int(i) for i in my_string if i.isdigit()]
    # 리스트의 합 반환
    return sum(result)
            