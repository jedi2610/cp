from collections import defaultdict
import re

holdingColor = set()
containedIn = defaultdict(set)
bagCount = defaultdict(list)
totalCount = 0


def isThere(color):
    global containedIn, holdingColor
    for c in containedIn[color]:
        holdingColor.add(c)
        isThere(c)


def countBags(color):
    global bagCount, containedIn
    totalCount = 0
    for count, bagColor in bagCount[color]:
        totalCount += count + (count * countBags(bagColor))
    return totalCount


def main():
    global containedIn, holdingColor
    file = open('input', 'r')
    input = file.readlines()
    containedIn = defaultdict(set)

    for line in input:
        containerColor = re.findall(r'(.*) bags contain', line)[0]
        for count, color in re.findall(r'(\d) (\w+ \w+) bags?', line):
            containedIn[color].add(containerColor)
            bagCount[containerColor].append((int(count), color))

    isThere('shiny gold')
    print(len(holdingColor))
    print(countBags('shiny gold'))


if __name__ == "__main__":
    main()
