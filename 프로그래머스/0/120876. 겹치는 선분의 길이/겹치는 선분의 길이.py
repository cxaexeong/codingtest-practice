def solution(lines):
    ranges = [set(range(start, end)) for start, end in lines]
    
    overlap = (ranges[0] & ranges[1] | ranges[1] & ranges[2] | ranges[0] & ranges[2])
    
    return len(overlap)
