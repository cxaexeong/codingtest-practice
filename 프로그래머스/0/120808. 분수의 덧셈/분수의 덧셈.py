import math

def solution(numer1, denom1, numer2, denom2):
    numerator = (numer1*denom2) + (numer2*denom1)
    dominator = denom1 * denom2
    
    gcd = math.gcd(numerator, dominator)
    
    numerator //= gcd
    dominator //= gcd
    
    return [numerator, dominator]