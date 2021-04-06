from collections import defaultdict

t = int(input())

while t != 0:
    balance = 0
    seen = 1
    a = defaultdict(int)
    n = int(input())
    for i in map(int, input().split()):
        a[i]+=1
    a = dict(sorted(a.items(), key=lambda x: x[0]))
    for key, value in a.items():
        if balance + value + seen - 1 >= key:
            seen += (balance + value)
            balance = 0
        else:
            balance += value
    print(seen)
    t-=1
