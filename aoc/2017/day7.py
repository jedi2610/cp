from collections import defaultdict

def part1():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/input/7.txt", "r")
    lines = list(f.read().strip().split('\n'))
    children = set()
    names = list()

    for line in lines:
        words = line.split()
        names.append(words[0])
        if len(words) == 2:
            continue
        for child in words[3:]:
            children.add(child.strip(','))

    for name in names:
        if name not in children:
            print(name)

def part2():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/input/7.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/input/sample", "r")
    lines = list(f.read().strip().split('\n'))
    children = set()
    weights = defaultdict(list)

    for line in lines:
        words = line.split()
        weights[words[0]].append(int(words[1].strip('()')))
        if len(words) == 2:
            continue
        words = list(map(lambda x: x.strip(','), words))
        weights[words[0]].append(words[3:])
        for child in words[3:]:
            children.add(child)

    root = "bpvhwhh"
    # root = "tknk"
    dfs(root, weights)

def dfs(root, weights):
    sum = 0
    prev = 0
    ans = 0
    if len(weights[root]) == 1:
        return weights[root][0]

    correct = []
    for i, child in enumerate(weights[root][1]):
        ans = dfs(child, weights)
        if ans == None:
            return
        if (ans != prev and i):
            print(ans, prev, root, weights[root], child, weights[child])
            print(weights[weights[root][1][i-1]])
            print(correct)
            return None
        sum += ans
        correct.append(ans)
        prev = ans

    return sum + weights[root][0]

if __name__ == "__main__":
    # part1()
    part2()
