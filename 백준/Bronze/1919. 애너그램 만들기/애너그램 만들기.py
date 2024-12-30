from collections import Counter

# 두 문자열 입력
a = input()
b = input()

# 각 문자열의 문자 빈도수 계산
count_a = Counter(a)
count_b = Counter(b)

# 문자 차이 계산
diff = 0
for char in set(a + b):  # 두 문자열에 등장한 모든 문자
    diff += abs(count_a[char] - count_b[char])

# 결과 출력
print(diff)