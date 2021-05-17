def part1():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/5.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")
    lines = list(map(int, f.read().strip().split('\n')))
    steps = 0
    i = 0

    while (i >= 0 and i < len(lines)):
        prev = i
        i += lines[i]
        lines[prev] += 1
        steps += 1
    print(steps)

def part2():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/5.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")
    lines = list(map(int, f.read().strip().split('\n')))
    steps = 0
    i = 0

    while (i >= 0 and i < len(lines)):
        prev = i
        i += lines[i]
        if lines[prev] >= 3:
            lines[prev] -= 1
        else:
            lines[prev] += 1
        steps += 1
    print(steps)


if __name__ == "__main__":
    # part1()
    part2()
