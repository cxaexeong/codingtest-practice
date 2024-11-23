def solution(hp):
    general = hp // 5
    hp %= 5
    soldier = hp // 3
    hp %= 3
    worker = hp
    return general + soldier + worker