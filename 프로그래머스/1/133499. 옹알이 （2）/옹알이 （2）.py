import re

def solution(babbling):
    # 연속된 동일 패턴 방지 (정규식 사용)
    valid_pattern = re.compile(r"^(aya(?!aya)|ye(?!ye)|woo(?!woo)|ma(?!ma))+$")
    count = 0
    for word in babbling:
        if valid_pattern.match(word):
            count += 1
    return count