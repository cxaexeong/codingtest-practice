def solution(players, callings):
    # 선수 이름 -> 현재 인덱스 매핑 딕셔너리 생성
    player_indices = {player: i for i, player in enumerate(players)}
    
    for calling in callings:
        # 현재 불린 선수의 인덱스
        idx = player_indices[calling]
        
        # 불린 선수가 첫 번째가 아니라면 자리를 교체
        if idx > 0:
            # 바로 앞 선수와 현재 선수 교체
            prev_player = players[idx - 1]
            
            # 리스트에서 자리 교체
            players[idx], players[idx - 1] = players[idx - 1], players[idx]
            
            # 딕셔너리에서 인덱스 업데이트
            player_indices[calling] -= 1
            player_indices[prev_player] += 1
    
    return players