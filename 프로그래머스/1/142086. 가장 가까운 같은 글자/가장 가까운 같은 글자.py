def solution(s):
    last_seen = {} # 문자의 마지막 등장 위치를 기록하는 딕셔너리
    result = []
    
    for idx, char in enumerate(s):
        if char in last_seen: # 문자가 이전에 등장한 적 있다면
            result.append(idx - last_seen[char])
        else:
            result.append(-1)
        last_seen[char] = idx # 현재 문자의 위치를 기록
    
    return result
        
            
        