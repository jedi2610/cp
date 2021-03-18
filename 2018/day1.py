def main():
    file = open("input", "r")
    score = 0
    res = set()
    input = list(map(int, file.readlines()))

    for number in input:
        score += number
        res.add(score)

    print(res)

    i = 0
    while True:
        score += input[i]
        if score in res:
            print(score)
            break
        i += 1
        if i == len(input):
            i = 0


if __name__ == "__main__":
    main()
