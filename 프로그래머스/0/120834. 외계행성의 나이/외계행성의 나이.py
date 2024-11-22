def solution(age):
    alien_age = ''.join(chr(ord('a') + int(digit)) for digit in str(age))
    
    return alien_age