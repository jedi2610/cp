def main():
    file = open("input", "r")
    ans = set()

    for line in file.readlines():
        line = line.strip()
        binary = []
        for letter in line:
            if letter in ['B', 'R']:
                binary.append('1')
            else:
                binary.append('0')
        ans.add(int(''.join(binary), 2))

    print(max(ans))
    for i in ans:
        if i + 1 not in ans and i+2 in ans:
            print(i+1)
            break


if __name__ == "__main__":
    main()
