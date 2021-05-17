from collections import deque

file = open('sample', 'r')
L = [line.strip().replace(' ', '') for line in file.readlines()]


def part1(l, index):

    stack = deque()

    i = index
    while l[i] != ')':
        ch = l[i]

        if ch == '+':
            a = stack.popleft()
            b = 0
            i += 1

            if l[i] == '(':
                b, offset = part1(l, i+1)
                i = offset
            else:
                b = int(l[i])

            ans = a + b
            stack.append(ans)

        elif ch == '*':
            a = stack.popleft()
            i += 1
            b = 0

            if l[i] == '(':
                b, offset = part1(l, i+1)
                i = offset
            else:
                b = int(l[i])
            ans = a * b
            stack.append(ans)

        else:
            stack.append(int(ch))
        i += 1

    return stack[0], i


def part2(l, index):

    stack = deque()
    opStack = deque()

    i = index
    while l[i] != ')':
        ch = l[i]

        if ch == '+':
            a = stack.popleft()
            b = 0
            i += 1

            if l[i] == '(':
                b, offset = part1(l, i+1)
                i = offset
            else:
                b = int(l[i])

            ans = a + b
            stack.append(ans)

        elif ch == '*':
            opStack.append(ch)

        else:
            stack.append(int(ch))
        i += 1

    ans = 1
    for item in stack:
        ans *= item

    return ans, i


sum1 = 0
sum2 = 0
for l in L:
    l = '(' + l + ')'
    for i in range(len(l)):
        if l[i] == '(' and l[i+1] == '(':
            l = l[0:i+1] + '0+' + l[i+1:]

    ans, _ = part1(l, 1)
    sum1 += ans
    ans, _ = part2(l, 1)
    sum2 += ans

print(sum1)
print(sum2)
