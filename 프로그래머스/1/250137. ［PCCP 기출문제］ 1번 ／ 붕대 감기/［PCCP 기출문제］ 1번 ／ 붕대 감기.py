def solution(bandage, health, attacks):
    t, x, y = bandage  # 시전 시간, 초당 회복량, 추가 회복량
    max_health = health  # 최대 체력
    time = 0  # 현재 시간
    continuous_time = 0  # 연속 성공 시간

    for attack_time, damage in attacks:
        # 공격 직전까지 경과한 시간
        elapsed = attack_time - time

        # 회복 계산
        if elapsed > 0:
            # 초당 회복량 계산
            health = min(max_health, health + x * elapsed)

            # 추가 회복 처리
            continuous_time += elapsed
            if continuous_time >= t:
                # 추가 회복 발생 횟수 계산
                extra_heal_count = continuous_time // t
                health = min(max_health, health + y * extra_heal_count)
                continuous_time %= t

        # 공격 처리
        health -= damage
        if health <= 0:  # 체력이 0 이하가 되면 사망
            return -1
        
        # 공격 이후 초기화
        time = attack_time + 1
        continuous_time = 0  # 공격받으면 연속 성공 초기화

    # 마지막 공격 이후 회복 처리
    if continuous_time > 0:
        extra_heal_count = continuous_time // t
        health = min(max_health, health + y * extra_heal_count)

    return health
