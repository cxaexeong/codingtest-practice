def solution(id_list, report, k):
    # 중복 신고 제거
    report = set(report)
    
    # 신고당한 사용자 카운트
    reported_count = {}
    for re in report:
        user, declaration = re.split()
        if declaration not in reported_count:
            reported_count[declaration] = 0
        reported_count[declaration] += 1
    
    # 메일을 받을 사용자 계산
    mail_count = {user: 0 for user in id_list}
    for re in report:
        user, declaration = re.split()
        if reported_count[declaration] >= k:
            mail_count[user] += 1
    
    # 각 사용자별 메일 개수 반환
    return [mail_count[user] for user in id_list]
