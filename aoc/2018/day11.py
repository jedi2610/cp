import numpy
from collections import defaultdict


def main(sNo):
    values = defaultdict(int)
    ans = defaultdict(int)

    for x in range(1, 301):
        for y in range(1, 301):
            rId = x + 10
            tmp = ((rId * y) + sNo) * rId
            values[(x, y)] = int(str(tmp)[-3]) - 5

    for x in range(1, 301):
        for y in range(1, 301):
            for dx in range(3):
                for dy in range(3):
                    ans[(x, y)] += values[(dx+x, dy+y)]

    print(max(ans.items(), key=lambda x: x[1]))

    ans2 = defaultdict(int)
    for x in range(1, 251):
        for y in range(1, 251):
            for ct in range(20):
                for dx in range(ct):
                    for dy in range(ct):
                        ans2[(x, y, ct)] += values[(dx+x, dy+y)]
        print(x)

    print(max(ans2.items(), key=lambda x: x[1]))


if __name__ == '__main__':
    sNo = 1133
    main(sNo)
