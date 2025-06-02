n = int(input())
scores = list(map(int, input().split()))
m = max(scores)
new_scores = [(s / m) * 100 for s in scores]
avg = sum(new_scores) / n

print(avg)
    