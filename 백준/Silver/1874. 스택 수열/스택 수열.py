import sys
input = sys.stdin.readline

n = int(input())
sequence = [int(input()) for _ in range(n)]  # 입력 수열
stack = []
result = []
current = 1

for num in sequence:
    while current <= num:  # 목표 숫자에 도달할 때까지 push
        stack.append(current)
        result.append('+')
        current += 1
    
    if stack[-1] == num:  # 스택의 마지막 숫자가 목표 숫자와 같으면 pop
        stack.pop()
        result.append('-')
    else:
        print("NO")  # 목표 숫자를 만들 수 없으면 종료
        exit(0)

# 결과 출력
print('\n'.join(result))