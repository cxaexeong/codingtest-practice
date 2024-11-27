def solution(wallpaper):
    
    min_row, min_col = float('inf'), float('inf')
    max_row, max_col = float('-inf'), float('-inf')
    
    for row in range(len(wallpaper)):
        for col in range(len(wallpaper[0])):
            if wallpaper[row][col] == '#':
                min_row = min(min_row, row)
                min_col = min(min_col, col)
                max_row = max(max_row, row)
                max_col = max(max_col, col)
    return [min_row, min_col, max_row + 1, max_col+1]