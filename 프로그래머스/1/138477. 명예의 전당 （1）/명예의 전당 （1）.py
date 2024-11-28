def solution(k, score):
    hall_of_fame = []  # 명예의 전당 리스트
    result = []        # 최하위 점수 기록

    for s in score:
        hall_of_fame.append(s)             # 새로운 점수 추가
        hall_of_fame = sorted(hall_of_fame, reverse=True)  # 내림차순 정렬
        if len(hall_of_fame) > k:          # 상위 k명만 유지
            hall_of_fame.pop()             # 최하위 제거
        result.append(hall_of_fame[-1])    # 명예의 전당 최하위 점수 기록

    return result
