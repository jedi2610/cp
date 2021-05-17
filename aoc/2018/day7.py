from collections import defaultdict


def main():
    file = open("input")
    input = file.readlines()

    order = defaultdict(list)
    count = defaultdict(int)
    stack = []
    ans = []

    for line in input:
        line = line.split()
        before, start = line[1], line[-3]
        order[before].append(start)
        count[start] += 1

    SSD = defaultdict(int)
    SSD.update(count)
    startNodes = set(order).difference(set(count))
    endNode = set(count).difference(set(order))
    endNode = list(endNode)[0]
    for item in startNodes:
        stack.append(item)

    stack = sorted(set(stack), reverse=True)
    while stack:
        x = stack.pop()
        ans.append(x)

        for item in order[x]:
            count[item] -= 1
            if count[item] == 0:
                stack.append(item)
        stack = sorted(set(stack), reverse=True)

    print(''.join(ans))

    startNodes = set(order).difference(set(count))
    stack = []
    for item in startNodes:
        stack.append(item)
    stack = sorted(set(stack), reverse=True)

    workers = []
    workers.append([4, 3])
    days = 0
    while len(workers) > 0:

        for i in range(len(workers)):
            workers[i][1] += 1

        for i in range(len(workers)):
            try:
                if workers[i][0] == workers[i][1]:
                    x = workers[i][1]

                    c = chr(x + 4)
                    workers.remove([x, x])
                    if c == endNode:
                        print(days)
                        exit()
                    ss = order[c]
                    if ss:
                        for item in ss:
                            SSD[item] -= 1
                            if SSD[item] == 0:
                                stack.append(item)
                    stack = sorted(set(stack), reverse=True)
            except IndexError:
                break

        while len(workers) < 5:
            try:
                c = stack.pop()
                workers.append([ord(c) - 4, 0])
            except Exception:
                break

        days += 1

    print(days)


if __name__ == "__main__":
    main()
