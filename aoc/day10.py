from collections import defaultdict
import numpy as np

input = []
DP = defaultdict(int)
MYDP = defaultdict(int)


def rec(i):
    global input, DP
    if i == len(input) - 1:
        return 1

    if i in DP:
        return DP[i]

    ans = 0
    for j in range(i+1, len(input)):
        diff = input[j] - input[i]
        if diff <= 3:
            ans += rec(j)
        else:
            break

    DP[i] = ans
    return ans


def myAns():
    global input, MYDP
    for k in range(len(input)):
        ct = 0
        for j in range(k+1, len(input)):
            if input[j] - input[k] <= 3:
                ct += 1
            else:
                break

        if ct >= 2:
            prevScore = 0
            for _, value in MYDP.items():
                prevScore += value
            MYDP[k] = prevScore + ct

    print(MYDP)


def main():
    global input, DP
    file = open('sample1', 'r')
    input = list(map(int, file.readlines()))
    input.insert(0, 0)
    input.append(max(input) + 3)
    input = sorted(input)
    # MYDP[len(input)] = 1

    one = 0
    three = 0

    for i in range(len(input) - 1):
        diff = input[i+1] - input[i]
        if diff == 1:
            one += 1
        elif diff == 3:
            three += 1

    print(one*(three))
    # print(rec(0))
    myAns()
    print(input)
    print(max(MYDP.values()))
    print(MYDP[len(input)])


if __name__ == "__main__":
    main()
