def solution(quiz):
    answer = []
    
    for q in quiz:
        expression, result = q.split(" = ")
        
        if eval(expression) == int(result):
            answer.append("O")
        else:
            answer.append("X")
            
    return answer