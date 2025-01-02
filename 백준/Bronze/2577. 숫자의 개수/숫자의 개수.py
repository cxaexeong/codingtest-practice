a = int(input())
b = int(input())
c = int(input())

result = str(a * b * c)
arr = [0] * 10

for char in result:
    arr[int(char)] += 1

for count in arr:
    print(count)  
