def solution(number, limit, power):
    ans = []
    for i in range(1, number + 1):
        count = 0
        sqrt_i = int(i ** 0.5)
        for j in range(1, sqrt_i + 1):
            if i % j == 0:
                count += 1  # j는 약수
                if j != i // j:
                    count += 1  # i // j도 약수
        ans.append(count)
    
    # Limit과 power 처리
    for a in range(len(ans)):
        if ans[a] > limit:
            ans[a] = power
    return sum(ans)
