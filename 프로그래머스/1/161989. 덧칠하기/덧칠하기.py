def solution(n, m, section):
    count= 0
    current = 0 
    
    for start in section:
        if start > current:
            count += 1
            current = start + m - 1
            
    return count