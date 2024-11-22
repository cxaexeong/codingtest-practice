def solution(array, height):
    ans = []
    for i in array:
        if i > height:  # 머쓱이보다 키가 큰 경우만 포함
            ans.append(i)
    return len(ans)
