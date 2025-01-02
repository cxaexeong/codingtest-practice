import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a, b = input().split()
    
    sort_a = sorted(a)
    sort_b = sorted(b)

    if sort_a == sort_b:
        print("Possible")
    else:
        print("Impossible")
