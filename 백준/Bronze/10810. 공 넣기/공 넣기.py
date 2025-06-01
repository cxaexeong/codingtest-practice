n, m = map(int, input().split())
busket = [0] * n

for _ in range(m):
    i, j, k = map(int, input().split())
    for idx in range(i-1, j):
        busket[idx] = k
        
print(*busket)