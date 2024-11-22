# def solution(numbers, direction):
#     result = []
#     for i in numbers:
#         result.append(i)
#     if direction == "right":
#         result.append(result.pop(-1))
#     elif direction == "left":
#         result.append(result.pop(0))
#     return result
def solution(numbers, direction):
    if direction == "right":
        return [numbers[-1]] + numbers[:-1]
    if direction == "left":
        return numbers[1:] + [numbers[0]]