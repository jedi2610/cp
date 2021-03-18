def hasTwoNumbers(number):

    for i in range(0, 5):
        if number[i] == number[i+1]:
            if number.count(number[i]) == 2:
                return True

    return False


def main():

    stringFormat = list(map(str, range(387638, 919123 + 1)))
    passedFirst = []
    passedSecond = []

    for item in stringFormat:
        if item == "".join(sorted(item)):
            passedFirst.append(item)

    for item in passedFirst:
        if hasTwoNumbers(item):
            passedSecond.append(item)

    print(len(passedSecond))


if __name__ == "__main__":
    main()
