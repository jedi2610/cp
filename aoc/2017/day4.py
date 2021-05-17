from collections import Counter

def part1():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/4.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")
    lines = f.read().strip().split('\n')
    count = 0
    for line in lines:
        words = line.split(' ')
        flag = 1
        for word in words:
            if words.count(word) > 1:
                flag = 0
        if flag:
            count+=1
    print(count)

def part2():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/4.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/sample", "r")
    lines = f.read().strip().split('\n')
    count = 0
    for line in lines:
        words = line.split(' ')
        flag = 1
        for word in words:
            anagrams = list(filter(lambda x: (Counter(word) == Counter(x)), words))
            if len(anagrams) > 1:
                flag = 0
        if flag:
            count += 1
    print(count)


if __name__ == "__main__":
    part1()
    part2()
