def part1():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/6.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")
    lines = list(map(int, f.read().strip().split('\t')))
    # lines = list(map(int, f.read().strip().split(' ')))
    size = len(lines)
    configs = [lines]
    while True:
        maxNum = max(lines)
        idx = lines.index(maxNum)
        min = maxNum//size
        rem = maxNum%size
        lines[idx] = 0

        if min != 0:
            lines = [x + min for x in lines]
        if rem != 0:
            for i in range(idx+1, idx+1+rem):
                lines[i%size] += 1

        if tuple(lines) in configs:
            print("Part 2: ", len(configs) - configs.index(tuple(lines)))
            break
        configs.append(tuple(lines))
    print("Part 1: ", len(configs))


def part2():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/6.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")


if __name__ == "__main__":
    part1()
    # part2()
