import math

def part1():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/2.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")
    a = str(f.read()).split('\n')[:-1]
    sum = 0
    for line in a:
        nums = list(map(int, line.strip().split('\t')))
        diff = max(nums) - min(nums)
        sum += diff
    print(sum)

def part2():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/2.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")
    a = str(f.read()).split('\n')[:-1]
    sum = 0
    for line in a:
        nums = sorted(set(map(int, line.strip().split('\t'))), reverse=True)
        ans = 0
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                div = nums[i] / nums[j]
                if (div == math.floor(div)):
                    ans = div
                    break
            if (ans != 0):
                break
        sum += int(ans)
    print(sum)


if __name__ == "__main__":
    part1()
    part2()
