from collections import defaultdict

def checkCondition(line, val):
    ops = {'>': (lambda x,y: x > y), 
           '<': (lambda x,y: x < y), 
           '>=': (lambda x,y: x >= y), 
           '<=': (lambda x,y: x <= y), 
           '==': (lambda x,y: x == y), 
           '!=': (lambda x,y: x != y), 
           'inc': (lambda x,y: x + y), 
           'dec': (lambda x,y: x - y) }

    return ops[line[-2]](val[line[-3]], int(line[-1]))

def part1():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/input/8.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/input/sample", "r")
    lines = list(f.read().strip().split('\n'))
    val = defaultdict(int)
    for line in lines:
        line = line.strip().split()
        if not checkCondition(line, val):
            continue
        if line[1] == 'dec':
            val[line[0]] -= int(line[2])
        else:
            val[line[0]] += int(line[2])
        
    print(max(val.values()))

def part2():
    f = open("/mnt/Seagate/Code/cp/aoc/2017/input/8.txt", "r")
    # f = open("/mnt/Seagate/Code/cp/aoc/2017/input/sample", "r")
    lines = list(f.read().strip().split('\n'))
    val = defaultdict(int)
    maxVal = 0
    for line in lines:
        line = line.strip().split()
        if not checkCondition(line, val):
            continue
        if line[1] == 'dec':
            val[line[0]] -= int(line[2])
        else:
            val[line[0]] += int(line[2])
        maxVal = max(maxVal, val[line[0]])
        
    print(maxVal)


if __name__ == "__main__":
    part1()
    part2()
