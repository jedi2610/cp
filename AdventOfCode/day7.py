from itertools import permutations


def processInstructions(instructions: list, setting: int, signal: int):

    i = 0
    counter = 1
    while(i < len(instructions)):
        opCode = str(instructions[i]).zfill(5)
        modes = [opCode[2], opCode[1], opCode[0]]
        ans = 0

        if (opCode[-2:] == "99"):
            # halt
            return ans

        x, y, pos = instructions[i+1], instructions[i+2], instructions[i+3]

        try:
            x = x if(modes[0] == "1") else instructions[x]
            y = y if(modes[1] == "1") else instructions[y]
        except IndexError:
            pass

        if (opCode[-2:] == "01"):
            # add
            val = x + y
            instructions[pos] = val
            i += 4
        elif (opCode[-2:] == "02"):
            # multiply
            instructions[pos] = x * y
            i += 4
        elif (opCode[-2:] == "03"):
            # read
            # val = int(input())
            if (counter == 1):
                val = setting
            else:
                val = signal
            counter += 1
            pos = instructions[i+1]
            instructions[pos] = val
            i += 2
        elif (opCode[-2:] == "04"):
            # output
            # print(ans)
            i += 2
            return x
        elif (opCode[-2:] == "05"):
            # jump if true
            if (x != 0):
                i = y
            else:
                i += 3
        elif (opCode[-2:] == "06"):
            # jump if false
            if (x == 0):
                i = y
            else:
                i += 3
        elif (opCode[-2:] == "07"):
            # less than
            instructions[pos] = 1 if(x < y) else 0
            i += 4
        elif (opCode[-2:] == "08"):
            # equals
            instructions[pos] = 1 if(x == y) else 0
            i += 4


def part1(instructions):

    perms = list(permutations(range(5)))
    answers = list()

    for perm in perms:
        ans = 0
        for i in range(5):
            ans = processInstructions(instructions, perm[i], ans)
        answers.append(ans)

    print(max(answers))


def part2(instructions):

    perms = list(permutations(range(5, 10)))
    answers = list()
    answers.append(0)

    for perm in perms:
        ans = 0
        for i in range(len(perm)):
            ans = processInstructions(instructions, perm[i], ans)
        answers.append(ans)

    print(max(answers))


def main():

    file = open("input.txt", "r")
    instructions = list(map(int, file.readline().split(",")))
    # part1(instructions)
    part2(instructions)


if __name__ == "__main__":
    main()
