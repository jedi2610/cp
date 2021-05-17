def main():
    file = open("input.txt", "r")
    input = file.readlines()
    count = 0
    for i in input:
        number, letter, password = i.split(" ")
        low, high = [int(x) for x in number.split("-")]
        letter = letter[0]
        password.strip()
        # print((password[low-1] != letter and password[high-1] == letter),
        # (password[low-1] == letter and password[high-1] != letter))
        if ("qqqqrqfx" in password):
            print(password)
            print(password[low-1])
            print(password[high-1])
        if (password[low-1] == letter) ^ (password[high-1] == letter):
            count += 1

    print(count)


if __name__ == "__main__":
    main()
