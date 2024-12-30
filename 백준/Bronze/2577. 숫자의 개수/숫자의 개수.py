a = int(input())
b = int(input())
c = int(input())

total = str(a * b * c)  # 곱한 결과를 문자열로 변환
arr = [0] * 10  # 0~9 숫자 개수를 저장할 리스트

for char in total:  # total의 각 문자 확인
    arr[int(char)] += 1  # 해당 숫자 위치의 카운트를 증가

for count in arr:  # 결과 출력
    print(count)
