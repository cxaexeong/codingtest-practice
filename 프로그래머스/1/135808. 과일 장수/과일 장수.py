def solution(k, m, score):
    score.sort(reverse=True)  # 높은 점수부터 정렬
    ans = 0

    for i in range(0, len(score), m):
        if i + m <= len(score):  # m개씩 묶을 수 있는 경우만 처리
            group = score[i:i+m]
            ans += min(group) * m

    return ans
