def solution(name, yearning, photo):
    # 이름과 점수를 딕셔너리로 매핑
    score_map = {name[i]: yearning[i] for i in range(len(name))}
    
    # 각 사진의 점수를 계산
    result = []
    for p in photo:
        # 사진 속 인물들의 점수 합산
        total_score = sum(score_map.get(person, 0) for person in p)
        result.append(total_score)
    
    return result