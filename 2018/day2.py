def main():
    file = open("input", "r")
    input = [line.strip() for line in file.readlines()]
    two = 0
    three = 0
    for id in input:
        twoTrue = False
        threeTrue = False
        for letter in set(id):
            if id.count(letter) == 2 and twoTrue != True:
                twoTrue = True
                two += 1
            elif id.count(letter) == 3 and threeTrue != True:
                threeTrue = True
                three += 1

    print(two*three)
    # input = ['abcde', 'fghij', 'klmno', 'pqrst', 'fguij', 'axcye', 'wvxyz']

    i = 0
    while i+1 < len(input):
        j = i+1
        while j < len(input):
            outputList = [input[i][k] for k in range(
                len(input[i])) if input[i][k] != input[j][k]]
            if len(outputList) == 1:
                print(''.join([input[i][k] for k in range(
                    len(input[i])) if input[i][k] == input[j][k]]
                ))
                exit(0)
            j += 1
        i += 1


if __name__ == "__main__":
    main()
