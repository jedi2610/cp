from collections import defaultdict
from re import findall

file = open('sample1', 'r')
L = [line.strip() for line in file.readlines() if line.strip()]
L = sorted(L)

rules = defaultdict(list)
messages = []
for l in L:
    words = l.split(':')
    if len(words) > 1:
        # rule
        subRules = words[1].split('|')
        for rule in subRules:
            ints = list(map(int, findall(r'\d+', rule)))
            if len(ints) != 0:
                rules[int(words[0])].append(ints)
            else:
                rules[int(words[0])].append(words[1].strip().replace('"', ''))
    else:
        # message
        messages.append(words[0])


def checkMessage(i):
    global rules

    if rules[i][0] == 'a' or rules[i][0] == 'b':
        return rules[i][0]

    checkMsgs = []
    for rule in rules[i]:
        msg = ''
        for val in rule:
            ans = checkMessage(val)
            print(ans)
            msg += ans[0]
        checkMsgs.append(msg)

    return checkMsgs


ct = 0
for message in messages:
    checkMsgs = checkMessage(0)
    for msg in checkMsgs:
        if msg == message:
            ct += 1
            break
print(ct)
