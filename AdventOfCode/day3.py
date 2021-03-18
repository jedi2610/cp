import numpy as np
from matplotlib import pyplot as plt
from collections import Counter


def getCommonPoints(paths: list):
    points = list()
    points.append((0, 0))
    for path in paths:
        x, y = points[-1][0], points[-1][1]
        number = int(path[1:])
        if path.startswith("R"):
            for i in range(1, number + 1):
                points.append((x + i, y))
        elif path.startswith("L"):
            for i in range(1, number + 1):
                points.append((x - i, y))
        elif path.startswith("U"):
            for i in range(1, number + 1):
                points.append((x, y + i))
        else:
            for i in range(1, number + 1):
                points.append((x, y - i))

    return points[1:]


def part2(paths: list, commonPoints: list) -> dict:

    point = (0, 0)
    steps = dict()
    stepsTaken = 1
    for points in commonPoints:
        steps[str(points)] = 0

    for path in paths:
        x, y = point[0], point[1]
        number = int(path[1:])
        if path.startswith("R"):
            for i in range(1, number + 1):
                point = (x + i, y)
                if point in commonPoints and steps.get(str(point)) != None:
                    steps[str(point)] = stepsTaken
                stepsTaken += 1
        elif path.startswith("L"):
            for i in range(1, number + 1):
                point = (x - i, y)
                if point in commonPoints and steps.get(str(point)) != None:
                    steps[str(point)] = stepsTaken
                stepsTaken += 1
        elif path.startswith("U"):
            for i in range(1, number + 1):
                point = (x, y + i)
                if point in commonPoints and steps.get(str(point)) != None:
                    steps[str(point)] = stepsTaken
                stepsTaken += 1
        else:
            for i in range(1, number + 1):
                point = (x, y - i)
                if point in commonPoints and steps.get(str(point)) != None:
                    steps[str(point)] = stepsTaken
                stepsTaken += 1

    return steps


def main():

    file = open("input.txt", "r")
    path1 = file.readline().split(",")
    path2 = file.readline().split(",")
    cable1 = getCommonPoints(path1)
    cable2 = getCommonPoints(path2)
    commonPoints = set(cable1).intersection(cable2)
    distance = [abs(point[0]) + abs(point[1]) for point in commonPoints]
    print(min(distance))
    steps1 = part2(path1, commonPoints)
    steps2 = part2(path2, commonPoints)
    shortSteps = list()
    cdict = Counter(steps1) + Counter(steps2)
    shortSteps = cdict.values()
    print(min(shortSteps))


if __name__ == "__main__":
    main()
