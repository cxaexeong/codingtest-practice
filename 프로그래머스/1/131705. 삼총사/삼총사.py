import itertools

def solution(number):
    result = 0
    # itertools.combinations 호출 시 괄호 사용
    combinations = itertools.combinations(number, 3)
    
    for combo in combinations:
        if sum(combo) == 0:
            result += 1
    
    return result
