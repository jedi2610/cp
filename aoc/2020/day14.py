from collections import defaultdict
from itertools import combinations
import re


def getAddr(binary, floating):
    if len(floating) == 0:
        return [binary]
    print("hello")
    ls = [0, 1] * len(floating)
    print(ls)
    comb = combinations(ls)
    print(len(list(comb)))


file = open('input', 'r')
instructions = [line.strip() for line in file.readlines()]
mem = defaultdict(int)
mask = ''

for line in instructions:
    if line.startswith('mask'):
        mask = line.split('=')[1].strip()
    else:
        addr, val = re.findall(r'\d+', line)
        binary = bin(int(addr)).replace('0b', '')
        binary = list(binary.zfill(36))

        floating = []
        for i in range(len(mask)):
            if mask[i] == '1':
                binary[i] = mask[i]
            elif mask[i] == 'X':
                floating.append(i)

        getAddr(binary, floating)
        mem[addr] = int(''.join(binary), 2)


sum = 0
for value in mem.values():
    sum += value

print(sum)
