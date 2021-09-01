from collections import defaultdict
from itertools import combinations

# visualized this as a graph problem so gave it a shot
# it worked well but there is more room for improvement in the main for loop

MAXVAL = 10000000
n, m = map(int, input().split())
price = list(map(int, input().split()))
match = defaultdict(list)
minPrice = MAXVAL

for _ in range(m):
    i, j = map(int, input().split())
    match[i].append(j)
    match[j].append(i)

match = dict(sorted(match.items(), key=lambda x: len(x[1]), reverse=True))

for item in match.items():
    if len(item[1]) < 2:
        break
    i = item[0]
    for temp in combinations(item[1], 2):
        j, k = temp
        if k not in match[j]:
            continue
        minPrice = min(minPrice, price[i-1] + price[j-1] + price[k-1])

if minPrice == MAXVAL:
    print(-1)
else:
    print(minPrice)
