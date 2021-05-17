# from matplotlib import pyplot as plt
# from time import sleep
# import matplotlib
# import numpy as np
# import re


# def main():
#     file = open('input', 'r')
#     print(matplotlib.backends.backend)
#     input = file.readlines()
#     positions = []
#     velocities = []
#     for line in input:
#         x, y, vx, vy = re.findall(r'-?\d+', line)
#         pos = (int(x), int(y))
#         vel = (int(vx), int(vy))
#         positions.append(pos)
#         velocities.append(vel)

#     ct = 1
#     # for p in [(1, 2), (4, 5)]:
#     for p in positions:
#         plt.scatter(*p)
#     plt.show()
#     plt.cla()

#     for _ in range(5000):
#         for j in range(len(positions)):
#             positions[j] = (positions[j][0] + (10 * velocities[j][0]),
#                             positions[j][1] + (10 * velocities[j][1]))

#         if ct > 9000:
#             plt.cla()
#             plt.xlabel("xpos")
#             plt.ylabel("ypos")
#             plt.title("secret message")
#             for p in positions:
#                 plt.scatter(*p)
#             plt.show()
#         ct += 10


# if __name__ == "__main__":
#     main()

from re import findall

file = open('input', 'r')
input = file.readlines()

data = []
for line in input:
    x, y, vx, vy = findall(r'-?\d+', line)
    data.append((int(x), int(y), int(vx), int(vy)))

print(data[9])

boxes = []
for sec in range(20000):
    minx, maxx, miny, maxy = 10000, 0, 10000, 0
    for x, y, vx, vy in data:
        minx = min(minx, x + sec * vx)
        maxx = max(maxx, x + sec * vx)
        miny = min(miny, y + sec * vy)
        maxy = max(maxy, y + sec * vy)
    boxes.append([maxx, minx, maxy, miny])

box = min(maxx - minx + maxy - miny for maxx, minx, maxy, miny in boxes)
for sec, (maxx, minx, maxy, miny) in enumerate(boxes):
    if box == maxx - minx + maxy - miny:
        break

grid = [[' ']*(maxx - minx + 1) for j in range(miny, maxy + 1)]
for (x, y, vx, vy) in data:
    grid[y + sec * vy - miny][x + sec * vx - minx] = '#'

for row in grid:
    print(''.join(row))

print(sec)
