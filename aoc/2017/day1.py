def part1():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/1.txt", "r")
    a = str(f.read()).strip()
    sum = 0
    for i in range(0, len(a) - 2):
        if (a[i] == a[i+1]):
            sum += int(a[i])
    if a[len(a)-1] == a[0]:
        sum += int(a[0])
    print(sum)

def part2():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/1.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")
    a = str(f.read()).strip()
    mid = len(a) // 2
    size = len(a)
    sum = 0
    for i in range(0, len(a) - 1):
        if (a[i] == a[(i+mid) % size]):
            sum += int(a[i])
    print(sum)


if __name__ == "__main__":
    part2()
