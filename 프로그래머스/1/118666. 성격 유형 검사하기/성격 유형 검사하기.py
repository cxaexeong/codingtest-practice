from collections import defaultdict

def solution(survey, choices):
    # 각 성격 유형의 점수 초기화
    scores = defaultdict(int)
    
    # 점수 매핑
    for i in range(len(survey)):
        type1, type2 = survey[i]
        choice = choices[i]
        
        if choice < 4:      # 비동의 쪽
            scores[type1] += 4 - choice
        elif choice > 4:    # 동의 쪽
            scores[type2] += choice - 4
    
    # 최종 성격 유형 결정
    result = ""
    result += "R" if scores["R"] >= scores["T"] else "T"
    result += "C" if scores["C"] >= scores["F"] else "F"
    result += "J" if scores["J"] >= scores["M"] else "M"
    result += "A" if scores["A"] >= scores["N"] else "N"
    
    return result