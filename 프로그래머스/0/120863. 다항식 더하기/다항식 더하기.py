def solution(polynomial):
    
    x_sum = 0
    num_sum = 0
    
    terms = polynomial.split(" + ")
    
    for term in terms:
        if 'x' in term:
            if 'x' == term:
                x_sum += 1
            else:
                # 계수를 가져옴
                x_sum += int(term[:-1])
        
        else:
            num_sum += int(term)
        
    
    # 결과 포매팅
    result = []
    if x_sum:
        result.append(f"{x_sum}x" if x_sum > 1 else "x")
    if num_sum:
        result.append(str(num_sum))
    
    return " + ".join(result)