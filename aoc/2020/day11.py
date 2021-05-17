from collections import defaultdict
from copy import deepcopy

R = 0
C = 0


def solve(layout, isPart1):
    canSee = 4 if isPart1 else 5
    while True:
        change = False
        temp = deepcopy(layout)

        for i in range(R):
            for j in range(C):

                if layout[i][j] == '.':
                    continue

                ct = 0
                for x, y in [(0, -1), (0, +1), (-1, 0), (1, 0), (1, 1), (-1, -1), (-1, 1), (1, -1)]:
                    dx = i + x
                    dy = j + y
                    while 0 <= dx < R and 0 <= dy < C and layout[dx][dy] == '.' and not isPart1:
                        dx += x
                        dy += y
                    if 0 <= dx < R and 0 <= dy < C and layout[dx][dy] == '#':
                        ct += 1

                if layout[i][j] == 'L' and ct == 0:
                    temp[i][j] = '#'
                    change = True
                elif layout[i][j] == '#' and ct >= canSee:
                    temp[i][j] = 'L'
                    change = True

        if not change:
            break
        layout = deepcopy(temp)

    occupied = 0
    for i in range(R):
        for j in range(C):
            if layout[i][j] == '#':
                occupied += 1

    return occupied


def main():
    global R, C

    file = open('sample', 'r')
    input = [list(line.strip()) for line in file.readlines()]

    R = len(input)
    C = len(input[0])
    print(solve(deepcopy(input), True))
    print(solve(deepcopy(input), False))


if __name__ == "__main__":
    main()
