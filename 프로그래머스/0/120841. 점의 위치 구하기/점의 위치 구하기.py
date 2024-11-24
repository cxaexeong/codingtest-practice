def solution(dot):
    if dot[0] > 0 and dot[1] > 0:
        return 1  # 1사분면
    elif dot[0] < 0 and dot[1] > 0:
        return 2  # 2사분면
    elif dot[0] < 0 and dot[1] < 0:
        return 3  # 3사분면
    elif dot[0] > 0 and dot[1] < 0:
        return 4  # 4사분면
