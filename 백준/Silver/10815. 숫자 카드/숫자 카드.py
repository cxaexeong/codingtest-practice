n = int(input())
n_lst = list(map(int, input().split()))

m = int(input())
m_lst = list(map(int, input().split()))

dict = {}
for i in range(n):
    dict[n_lst[i]] = -1
    
for i in m_lst:
    if i in dict:
        print(1, end=' ')
    else:
        print(0, end=' ')