import re

def solution(babbling):
    valid_pattern = re.compile("^(aya|ye|woo|ma)+$")
    count = 0
    for word in babbling:
        if valid_pattern.match(word):
            count += 1
    return count