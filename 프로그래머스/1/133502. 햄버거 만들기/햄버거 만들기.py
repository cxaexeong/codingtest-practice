# def solution(ingredient):
#     count = 0
#     # 1-빵, 2-야채, 3-고기
#     for i in range(len(ingredient) - 2):
#         if ingredient[i:i+3] == [1,2,3]:
#             count += 1
#     return count

def solution(ingredient):
    stack = []
    count = 0

    for i in ingredient:
        stack.append(i)  # 재료를 스택에 추가

        # 스택의 마지막 4개의 패턴이 [1, 2, 3, 1]과 동일한지 확인
        if len(stack) >= 4 and stack[-4:] == [1, 2, 3, 1]:
            count += 1  # 햄버거 카운트 증가
            del stack[-4:]  # 햄버거 패턴 제거 (슬라이싱 대신 효율적으로 동작)

    return count




    
            