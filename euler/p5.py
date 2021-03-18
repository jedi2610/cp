from collections import defaultdict
from math import lcm

# https://projecteuler.net/thread=5;page=5#105775
# question is to find the number that is divisible by all numbers from 1-20
# if you think about it (which i certainly didn't and this solution is based
# on a post on this problem's thread) it's just extended lcm of all the numbers
# from 1 till 20 so and lcm is just the least common multiple - the first number
# that is divisible by both the given numbers say x and y. so this problem is just
# the lcm(1,2,3....20) but that is kinda slow and we have to do something better


number = 20
prev = 2

for i in range(2, number):
    prev = lcm(prev, i+1)

print(prev)
