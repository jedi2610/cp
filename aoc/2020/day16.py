import re
from collections import defaultdict

file = open('input', 'r')
input = [line.strip() for line in file. readlines()]

ct = 0
fieldVals = set()
names = []
myTicket = []
nearbyTickets = []
fieldRanges = defaultdict(list)
candidates = defaultdict(list)
i = 0

for line in input:
    if not line:
        ct += 1
        continue

    if ct == 0:
        names.append(line.split(':')[0])
        vals = [int(x) for x in re.findall(r'\d+', line)]
        fieldRanges[i].extend(vals)
        list1 = list(range(vals[0], vals[1]+1))
        list2 = list(range(vals[2], vals[3]+1))
        fieldVals.update(list1)
        fieldVals.update(list2)
        i += 1
    elif ct == 1:
        myTicket = [int(x) for x in line.split(',')]
    else:
        ticket = [int(x) for x in line.split(',')]
        nearbyTickets.append(ticket)

validTickets = []
invalidSum = 0
for ticket in nearbyTickets:
    ct = 0
    for val in ticket:
        if val not in fieldVals:
            ct += 1
            invalidSum += val
    if ct == 0:
        validTickets.append(ticket)

for i in range(20):
    candidates[i] = list(range(0, 20))

for ticket in validTickets:
    for i, val in enumerate(ticket):
        for j, item in enumerate(fieldRanges.values()):
            if not (item[0] <= val <= item[1] or item[2] <= val <= item[3]):
                try:
                    candidates[i].remove(j)
                except ValueError:
                    pass


last = sorted(candidates.items(), key=lambda x: len(x[1]))
for i in range(len(last)):
    toRemove = last[i][1][0]
    for j in range(i+1, len(last)):
        last[j][1].remove(toRemove)

finalVal = 1
for i in range(len(last)):
    current = names[last[i][1][0]]
    if current.startswith('departure'):
        finalVal *= myTicket[last[i][0]]

print(invalidSum)
print(finalVal)
