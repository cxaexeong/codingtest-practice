import sys
input = sys.stdin.readline

n = int(input())  # 탑의 개수
heights = list(map(int, input().split()))  # 각 탑의 높이
stack = []  # (높이, 인덱스)를 저장할 스택
result = []  # 결과를 저장할 리스트

for i in range(n):
    while stack:
        # 현재 탑의 높이가 스택의 탑 높이보다 작거나 같으면 신호를 받을 수 있음
        if stack[-1][0] >= heights[i]:
            result.append(stack[-1][1] + 1)  # 1-based index
            break
        else:
            stack.pop()  # 스택에서 제거

    if not stack:  # 신호를 받을 탑이 없을 경우
        result.append(0)

    # 현재 탑을 스택에 추가
    stack.append((heights[i], i))

print(' '.join(map(str, result)))  # 결과 출력\