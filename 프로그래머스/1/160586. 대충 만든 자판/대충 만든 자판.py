def solution(keymap, targets):
    # 1. 각 문자의 최소 입력 횟수를 저장하는 딕셔너리 생성
    min_presses = {}
    
    for keys in keymap:
        for i, char in enumerate(keys):
            if char in min_presses:
                min_presses[char] = min(min_presses[char], i + 1)  # 최소 횟수 갱신
            else:
                min_presses[char] = i + 1  # 입력 횟수 저장
    
    # 2. 각 target에 대해 최소 입력 횟수 계산
    result = []
    for target in targets:
        total_presses = 0
        for char in target:
            if char in min_presses:
                total_presses += min_presses[char]
            else:
                total_presses = -1  # 입력 불가능한 문자가 있음
                break
        result.append(total_presses)
    
    return result