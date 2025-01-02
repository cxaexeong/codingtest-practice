n = input()
arr = [0] * 10

for digit in n:
    arr[int(digit)] += 1
    
arr[6] = (arr[6] + arr[9] + 1) // 2
arr[9] = 0

print(max(arr))