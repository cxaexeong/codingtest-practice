a = int(input())
b = int(input())
c = int(input())

result = a*b*c
count = [0] * 10

for digit in str(result):
    count[int(digit)] += 1

for c in count:
    print(c)
