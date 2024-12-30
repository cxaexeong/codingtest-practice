n, k = map(int, input().split())
rooms = [[0] * 2 for _ in range(6)]  # 학년별, 성별 학생 수를 저장 (6학년, 성별 2개)

for _ in range(n):
    s, y = map(int, input().split())  # 성별(s), 학년(y)
    rooms[y - 1][s] += 1

count = 0
for grade in rooms:
    for students in grade:
        count += (students + k - 1) // k  # 학생 수를 k로 나눈 방의 개수 계산

print(count)
