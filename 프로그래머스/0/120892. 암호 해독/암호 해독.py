# def solution(cipher, code):
#     ans = []
#     for char,count in cipher.items():
#         if count == code:
#             ans.append(char)
#     return ''.join(ans)
def solution(cipher, code): 
    # code 간격으로 문자 추출
    return ''.join(cipher[i] for i in range(code - 1, len(cipher), code))