from copy import deepcopy
from collections import deque


def main():
    file = open('input', 'r')
    prevState = deque(
        list(file.readline().strip().replace('initial state: ', '')))
    prevState.extendleft(['.'] * 5)
    prevState.extend(['.'] * 10)
    prevState = list(prevState)

    rules = {line.split('=>')[0].strip(): line.split('=>')[1].strip()
             for line in file.readlines() if line.strip()}
    i, ct = 1, 0

    while i <= 20:
        newState = deepcopy(prevState)
        # current = newState.index('#')
        current = 5

        while current < len(newState):
            pot = ''.join(prevState[current-2:current+3])
            if pot in rules:
                newState[current] = rules[pot]

            current += 1

        ct += newState.count('#')
        print(''.join(prevState))
        print(''.join(newState))
        prevState = deepcopy(newState)
        i += 1

    print(ct)


if __name__ == "__main__":
    main()
