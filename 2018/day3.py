def main():
    # 7 @ 129,812: 18x17
    seen = dict()
    file = open("input", "r")
    for line in file.readlines():
        line = line.strip()
        info = line.split()
        id = info[0][1:]
        w, h = map(int, info[-1].split('x'))
        x, y = info[2].split(',')
        x = int(x)
        y = int(y[:-1])
        for dx in range(w):
            for dy in range(h):
                try:
                    seen[(x+dx, y+dy)] += 1
                except KeyError:
                    seen[(x+dx, y+dy)] = 1

    for line in open("input", "r").readlines():
        line = line.strip()
        info = line.split()
        id = info[0][1:]
        w, h = map(int, info[-1].split('x'))
        x, y = info[2].split(',')
        x = int(x)
        y = int(y[:-1])
        isOkay = True
        for dx in range(w):
            for dy in range(h):
                if seen[(x+dx, y+dy)] > 1:
                    isOkay = False
        if isOkay:
            print(id)

    count = 0
    for (x, y), ans in seen.items():
        if ans >= 2:
            count += 1

    print(count)


if __name__ == "__main__":
    main()
