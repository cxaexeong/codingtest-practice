hour, minute = map(int, input().split())
time = int(input())

if (time + minute) // 60:
    hour += (time + minute) // 60
    minute = (time + minute) % 60
else:
    minute += time

while hour > 23:
    hour %= 24

print(hour, minute)
    