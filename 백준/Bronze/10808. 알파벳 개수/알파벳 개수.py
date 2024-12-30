s = input()
counts = [0] * 26

for char in s:
    counts[ord(char) - ord('a')] += 1 # 알파벳 인덱스 계산

print(*counts)
