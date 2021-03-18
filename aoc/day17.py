file = open('input', 'r')

L = [line.strip() for line in file.readlines()]

current = set()
for r, l in enumerate(L):
    for c, ch in enumerate(l):
        if ch == '#':
            current.add((r, c, 0, 0))

for _ in range(6):
    new = set()
    print(len(current))
    for x in range(-10, 14):
        for y in range(-10, 14):
            for z in range(-8, 8):
                for w in range(-8, 8):
                    nbr = 0
                    for dx in [-1, 0, 1]:
                        for dy in [-1, 0, 1]:
                            for dz in [-1, 0, 1]:
                                for dw in [-1, 0, 1]:
                                    if dx != 0 or dy != 0 or dz != 0 or dw != 0:
                                        if (x+dx, y+dy, z+dz, w+dw) in current:
                                            nbr += 1

                    if nbr == 3 and (x, y, z, w) not in current:
                        new.add((x, y, z, w))
                    if nbr in [2, 3] and (x, y, z, w) in current:
                        new.add((x, y, z, w))

    current = new

print(len(current))
