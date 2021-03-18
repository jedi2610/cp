def main():
    file = open('input', 'r')
    instructions = file.readlines()
    x, y = 0, 0
    wx, wy = 10, 1
    facing = 1
    DX = [0, 1, 0, -1]
    DY = [1, 0, -1, 0]
    dirs = ['N', 'E', 'S', 'W']

    for line in instructions:
        line = line.strip()
        number = int(line[1:])
        if line.startswith('N'):
            wy += number
        elif line.startswith('S'):
            wy -= number
        elif line.startswith('E'):
            wx += number
        elif line.startswith('W'):
            wx -= number
        elif line.startswith('L'):
            # replace (x,y) with (−y,x). That will rotate 90 degrees counterclockwise about the origin.
            for _ in range(number//90):
                wx, wy = -wy, wx
                # facing = int((facing + 3 * (number/90)) % 4)
        elif line.startswith('R'):
            # To rotate clockwise, replace (x,y) with (y,−x).
            for _ in range(number//90):
                wx, wy = wy, -wx
                # facing = int((facing + 1 * (number/90)) % 4)
        elif line.startswith('F'):
            x += (wx * number)
            y += (wy * number)

        print(line, dirs[facing], (x, y), (wx, wy))

    print(abs(x) + abs(y))


if __name__ == "__main__":
    main()
