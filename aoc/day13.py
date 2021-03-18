from collections import defaultdict

file = open('input', 'r')
timestamp = int(file.readline())
ids = [int(x) for x in file.readline().split(',') if x != 'x']

best = (1000000, 1999)
for id in ids:
    time = timestamp
    while time % id != 0:
        time += 1
    wait = time-timestamp
    if wait < best[0]:
        best = (wait, id)

print(best)
print(best[0] * best[1])
