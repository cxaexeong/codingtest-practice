n = int(input()) 
for _ in range(n):
    a, b = map(sorted, list(input().split()))
    # input.split: "abc cba" -> ['abc', 'cba']
    # map(sorted..): 'abc' - > ['a','b','c'], 'cba' -> ['a','b','c']
    print(['Impossible', 'Possible'][a==b])
    # [a==b] 인덱싱 도구: False, True
    