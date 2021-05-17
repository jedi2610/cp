from collections import defaultdict, deque


def main():
    file = open('input', 'r')
    input = file.readline().split()

    players, marbles = int(input[0]), int(input[-2])
    circle = [0]
    playerScore = defaultdict(int)
    currentMarblePos = 0
    print(marbles*100)

    for i in range(1, (marbles*100)+1):

        if i % 1000 == 0:
            print(i)
        if (i % 23) == 0:
            currentMarblePos = (currentMarblePos - 7 +
                                len(circle)) % len(circle)
            playerScore[i % players] += i
            playerScore[i % players] += circle.pop(currentMarblePos)
        else:
            # currentMarblePos = (currentMarblePos+2) % len(circle)
            if currentMarblePos == len(circle) - 1:
                currentMarblePos = 1
            else:
                currentMarblePos = currentMarblePos + 2

            circle.insert(currentMarblePos, i)

    print(max(playerScore.values()))
    # print(playerScore)


def play_game(max_players, last_marble):
    scores = defaultdict(int)
    circle = deque([0])

    for marble in range(1, last_marble + 1):
        if marble % 23 == 0:
            circle.rotate(7)
            scores[marble % max_players] += marble + circle.pop()
            circle.rotate(-1)
        else:
            circle.rotate(-1)
            circle.append(marble)

    return max(scores.values())


if __name__ == "__main__":
    # main()
    print(play_game(446, 71522 * 100))
