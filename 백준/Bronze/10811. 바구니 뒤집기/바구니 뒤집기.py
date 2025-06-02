n, m = map(int, input().split())
baskets = [i+1 for i in range(n)]

for _ in range(m):
    i, j = map(int, input().split())
    baskets[i-1: j] = reversed(baskets[i-1:j])
print(*baskets)