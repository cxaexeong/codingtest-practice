import sys
input = sys.stdin.readline

n = int(input())
heights = [int(input()) for _ in range(n)]

stack = []
count = 0

for height in heights:
    while stack and stack[-1] <= height:
        stack.pop()
    
    count += len(stack)
    stack.append(height)
    
print(count)