def solution(rsp):
    # 이길 수 있는 경우의 대응 관계를 딕셔너리로 정의
    win = {'2':'0', '0':'5', '5':'2'}
    # rsp의 각 문자에 대해 대응되는 이긴 결과를 찾아 반환
    return ''.join(win[char] for char in rsp)