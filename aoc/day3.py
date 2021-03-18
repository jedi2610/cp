import fileinput


def main():
    file = open("input", "r")
    input = [line.strip() for line in file.readlines()]
    x, y = (0, 0)
    count = 0

    while y < len(input)-1:
        x += 1
        y += 2
        if input[y][x % len(input[y])] == "#":
            count += 1

    print(count)


if __name__ == "__main__":
    main()
