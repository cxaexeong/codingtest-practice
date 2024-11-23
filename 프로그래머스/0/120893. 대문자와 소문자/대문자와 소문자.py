def solution(my_string):
    copy_my_string = my_string
    result = []
    for i in copy_my_string:
        if i.islower():
            result.append(i.upper())
        elif i.isupper():
            result.append(i.lower())
    return ''.join(result)