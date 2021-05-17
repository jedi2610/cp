def main():
    file = open("input.txt", "r")
    input = list(map(int, file.readlines()))
    for number in input:
        another = 2020 - number
        if another in input:
            print(number, another)
            print(number * another)
            break


def part2():
    file = open("/mnt/Seagate/Code/cp/aoc/2020/input.txt", "r")
    input = list(map(int, file.readlines()))
    for i in range(len(input)):
        for j in range(i+1, len(input)):
            for k in range(j+1, len(input)):
                if input[i] + input[j] + input[k] == 2020:
                    print(input[i] * input[j] * input[k])


if __name__ == "__main__":
    part2()
