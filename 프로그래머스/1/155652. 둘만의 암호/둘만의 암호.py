def solution(s, skip, index):
    
    alphabet = [chr(i) for i in range(97,123) if chr(i) not in skip]
    
    result = []
    for char in s:
        current_index = alphabet.index(char)
        new_index = (current_index + index) % len(alphabet)
        result.append(alphabet[new_index])
    return ''.join(result)