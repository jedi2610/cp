def getAnswer(intCodes):

    i = 0
    while (i < len(intCodes)):
        intCode = intCodes[i]
        x = intCodes[i + 1]
        y = intCodes[i + 2]
        res = intCodes[i + 3]
        
        if (intCode == 99):
            break
        elif (intCode == 1):
            intCodes[res] = intCodes[x] + intCodes[y]
        elif (intCode == 2):
            intCodes[res] = intCodes[x] * intCodes[y]
        i += 4
    return intCodes[0]

def main():

    i, j = 0, 0
    isDone = False 
    file = open("input.txt", "r")
    intCodes = list(map(int, file.readlines()[0].split(",")))
    
    for i in range(0, 100):
        for j in range(0, 100):
            intCodeDuplicate = list(intCodes)
            intCodeDuplicate[1], intCodeDuplicate[2] = i, j
            answer = getAnswer(intCodeDuplicate)
            if (answer == 19690720):
                print(i, j)
                isDone = True
                break
        if (isDone):
            break

if __name__ == "__main__":
    main()
