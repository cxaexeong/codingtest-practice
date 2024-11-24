def solution(array):
    max_arr = max(array)
    len_arr = array.index(max_arr)
    return [max_arr, len_arr]