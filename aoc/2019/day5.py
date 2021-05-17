def readOpCode(instructions):

    i = 0
    while(i < len(instructions)):
        opCode = str(instructions[i]).zfill(5)
        modes = [opCode[2], opCode[1], opCode[0]]

        if (opCode[-2:] == "99"):
            # halt
            break

        x, y, pos = instructions[i+1], instructions[i+2], instructions[i+3]
        x = x if(modes[0] == "1") else instructions[x]
        y = y if(modes[1] == "1") else instructions[y]

        if (opCode[-2:] == "01"):
            # add
            val = x + y
            instructions[pos] = val
            i += 4
        elif (opCode[-2:] == "02"):
            # multiply
            val = x * y
            instructions[pos] = val
            i += 4
        elif (opCode[-2:] == "03"):
            # read
            val = int(input())
            pos = instructions[i+1]
            instructions[pos] = val
            i += 2
        elif (opCode[-2:] == "04"):
            # output
            print(x)
            i += 2
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


def main():
    inputFile = open("input.txt", "r")
    input = list(map(int, inputFile.readline().split(",")))
    readOpCode(input)


if __name__ == "__main__":
    main()
