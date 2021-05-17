from collections import deque
from copy import deepcopy

file = open('input', 'r')
L = [line.strip() for line in file.readlines()]

player1 = deque()
player2 = deque()


def playGame(player1, player2):

    player1 = deque(player1)
    player2 = deque(player2)
    SEEN = set()

    winner = None
    while player1 and player2:

        key = (tuple(player1), tuple(player2))
        if key in SEEN:
            score = 0
            for i, val in enumerate(reversed(player1)):
                ans = val * (i+1)
                score += ans
            return 1, score

        SEEN.add(key)

        card1 = player1.popleft()
        card2 = player2.popleft()

        if len(player1) >= card1 and len(player2) >= card2:
            winner, _ = playGame(
                list(deepcopy(player1))[:card1], list(deepcopy(player2))[:card2])
        else:
            winner = 1 if card1 > card2 else 2

        if winner == 1:
            player1.append(card1)
            player1.append(card2)
        else:
            player2.append(card2)
            player2.append(card1)

    score = 0
    if player1:
        winner = 1
        for i, val in enumerate(reversed(player1)):
            ans = val * (i+1)
            score += ans
    else:
        for i, val in enumerate(reversed(player2)):
            ans = val * (i+1)
            score += ans
        winner = 2

    return winner, score


nextPlayer = False
for l in L:
    if not l:
        continue
    if 'Player' in l:
        if 'Player 2' in l:
            nextPlayer = True
        continue
    if nextPlayer:
        player2.append(int(l))
    else:
        player1.append(int(l))

winner, score = playGame(player1, player2)

print(score)
