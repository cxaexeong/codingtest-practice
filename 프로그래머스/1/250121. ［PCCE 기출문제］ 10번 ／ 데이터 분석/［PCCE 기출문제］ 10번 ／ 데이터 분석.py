# def solution(data, ext, val_ext, sort_by):    
#     for i in data:
#         if data[i][1] < val_ext:
#             if ext == "code":
#                 data.sorted(key = lambda x:x[i][0])
#             elif ext == "date":
#                 data.sorted(key = lambda x:x[i][1])
#             elif ext == "maximum":
#                 data.sorted(key = lambda x:x[i][2])
#             elif ext == "remain":
#                 data.sorted(key = lambda x:x[i][3])
#     return data
def solution(data, ext, val_ext, sort_by):
    # 필터링 기준 열 번호 찾기
    columns = {"code": 0, "date": 1, "maximum": 2, "remain": 3}
    ext_idx = columns[ext]
    sort_idx = columns[sort_by]
    
    # 조건을 만족하는 데이터 필터링
    filtered_data = [row for row in data if row[ext_idx] < val_ext]
    
    # 정렬
    sorted_data = sorted(filtered_data, key=lambda x: x[sort_idx])
    
    return sorted_data
