# def solution(n):
#     cnt = []
#     ans = []
#     for i in range(1,n+1):
#         for j in range(1, i+1):
#             if i % j == 0:
#                 cnt.append(j)
#                 if len(cnt) >= 3:
#                     ans.append(i)
#                 else:
#                     continue
#     return print(len(ans))
def solution(n):
    total_count = 0
    for num in range(1, n + 1):
        count = 0
        for i in range(1, num + 1):
            if num % i == 0:
                count += 1
            if count >= 3:
                total_count += 1
                break
    return total_count

