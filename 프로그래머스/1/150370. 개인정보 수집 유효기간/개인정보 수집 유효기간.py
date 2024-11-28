def solution(today, terms, privacies):
    # 오늘 날짜를 숫자로 변환 (YYYY.MM.DD -> 일 단위로 변환)
    def date_to_days(date):
        year, month, day = map(int, date.split('.'))
        return year * 12 * 28 + month * 28 + day

    today_in_days = date_to_days(today)
    
    # 약관 정보를 딕셔너리로 저장
    term_dict = {}
    for term in terms:
        key, value = term.split()
        term_dict[key] = int(value) * 28  # 유효기간(개월)을 일수로 변환

    expired = []  # 유효기간이 지난 개인정보 번호를 저장
    for idx, privacy in enumerate(privacies):
        start_date, term_type = privacy.split()
        start_date_in_days = date_to_days(start_date)
        
        # 유효기간의 마지막 날 계산
        expiry_date = start_date_in_days + term_dict[term_type] - 1
        
        # 유효기간이 지났으면 결과 리스트에 추가
        if expiry_date < today_in_days:
            expired.append(idx + 1)  # 번호는 1부터 시작

    return expired
