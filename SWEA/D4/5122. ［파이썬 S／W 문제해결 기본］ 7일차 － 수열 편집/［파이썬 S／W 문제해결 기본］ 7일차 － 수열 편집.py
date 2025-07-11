T = int(input())
for tc in range(1, T+1):
    n, m, l = map(int, input().split())
    arr = list(map(int, input().split()))
    flag = 1
    for _ in range(m):
        rule = input().split()
        if rule[0] == 'I':
            arr.insert(int(rule[1]), int(rule[2]))
        elif rule[0] == 'D':
            if not arr:
                flag = 0
                break
            arr.pop(int(rule[1]))
        else:
             arr[int(rule[1])] = int(rule[2])
    if len(arr) > l:
        if flag:
            print(f'#{tc} {arr[l]}')
        else:
            print(f'#{tc} -1')
    else:
        print(f'#{tc} -1')