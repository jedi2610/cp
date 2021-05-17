from collections import defaultdict, deque
from functools import partial


def main():
    spoken = [2, 1, 10, 11, 0, 6]
    # spoken = [0, 3, 6]
    values = {}

    for i, val in enumerate(spoken):
        values[val] = deque([0, i+1], 2)

    i, lastSpoken = len(spoken)+1, spoken[-1]

    spokenNow = 0
    while (i != 30000001):
        spokenNow = 0
        try:
            data = values[lastSpoken]
            if data[0] == 0:
                spokenNow = 0
            else:
                spokenNow = data[1] - data[0]
        except KeyError:
            values[lastSpoken] = deque([0, i], 2)
            spokenNow = 0

        try:
            values[spokenNow].append(i)
        except KeyError:
            values[spokenNow] = deque([0, i], 2)

        lastSpoken = spokenNow
        i += 1

    print(spokenNow)


if __name__ == "__main__":
    main()
