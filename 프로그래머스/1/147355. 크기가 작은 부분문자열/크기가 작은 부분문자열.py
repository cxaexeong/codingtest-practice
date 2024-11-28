def solution(t, p):
    result = 0
    p_len = len(p)
    t_len = len(t)
    lst = [t[i:i + p_len] for i in range(t_len - p_len + 1)] 
    
    for l in lst:
        if l <= p:
            result += 1
    return result
            