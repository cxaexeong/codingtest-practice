mods = set()

for _ in range(10):
    num = int(input())
    mods.add(num % 42)
print(len(mods))