def main():
    file = open("input", "r")
    input = file.readline().strip()
    listof = {}
    stack = []

    mappings = {}
    for letter in 'abcdefghijklmnopqrstuvwxyz':
        mappings[letter.lower()] = letter.upper()
        mappings[letter.upper()] = letter.lower()

    for letter in 'abcdefghijklmnopqrstuvwxyz':
        stack.clear()
        # dummy = [char for char in input if char.lower() != letter]
        dummy = input.replace(letter, "")
        dummy = dummy.replace(letter.upper(), "")
        print(dummy.count(letter), dummy.count(letter.upper()))
        for i in dummy:
            if stack and stack[-1] == mappings[i]:
                stack.pop()
            else:
                stack.append(i)
        listof[letter] = len(stack)

    print(min(listof.values()))


if __name__ == "__main__":
    main()
