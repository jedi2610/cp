from collections import deque


def main():
    file = open('input', 'r')
    input = list(map(int, file.readlines()))
    stack = deque()
    defNum = 0
    for number in input:
        if len(stack) >= 25:
            done = False
            for i in range(0, 25):
                predNum = stack[i]
                pairNum = number - predNum
                if pairNum in stack and pairNum != number:
                    done = True
                    stack.popleft()
                    stack.append(number)
                    break

            if not done:
                defNum = number
                break
        else:
            stack.append(number)

    print(defNum)
    for i in range(len(input)):
        sumList = set()
        j = int(i)
        while sum(sumList) < defNum:
            sumList.add(input[j])
            j += 1

        if sum(sumList) == defNum:
            print(min(sumList) + max(sumList))
            break


if __name__ == "__main__":
    main()
