def solution(dots):
    [[x1, y1], [x2, y2], [x3, y3], [x4, y4]] = dots
    ans1 = (y1-y2)*(x3-x4) == (y3-y4)*(x1-x2)
    ans2 = (y1-y3)*(x2-x4) == (y2-y4)*(x1-x3)
    ans3 = (y1-y4)*(x2-x3) == (y2-y3)*(x1-x4)
    return 1 if ans1 or ans2 or ans3 else 0