from collections import defaultdict
from math import sqrt
number = 600851475143
# number = 13195

# primes = set(range(2, int(sqrt(number))))
# primes = set(range(2, number))
# starting from 2 because it's the first prime number
# time complexity for this block of code is O(sqrt(n)log(n)) iirc
# since the question is to find the largest prime factor of the given number
# it is clear that the largest prime factor is less than sqrt(n)
# so i find all the prime numbers below sqrt(n) and then loop thro them to find
# all prime numbers which are factors of n and i use the max() func to find the max of it

# for i in range(2, 3):
#     for j in range(i+i, int(sqrt(number+1)), i):
#         primes.discard(j)
#         primes.discard(i//j)
# i can take this a step further as 2 in the only prime number and other prime numbers are odd
# compute this for 2 separately and continue with 3 and all other odd numebers i can start with 3 and increment by 2 which will always be odd
# for i in range(3, int(sqrt(number+1)), 2):
#     for j in range(i+i, int(sqrt(number+1)), i):
#         primes.discard(j)
#         primes.discard(i//j)

# since set doesn't remember the order i inserted the items in
# it necessary to sort them first

# for i in list(primes)[::-1]:
# for i in list(primes):
# if number % i == 0:
# print(i)
# break

# https://www.quora.com/What-is-the-largest-prime-factor-of-the-number-600851475143
# https://stackoverflow.com/questions/23287/algorithm-to-find-largest-prime-factor-of-a-number
# https://math.stackexchange.com/questions/63276/is-a-prime-factor-of-a-number-always-less-than-its-square-root#:~:text=The%20number%20left%20after%20repeatedly,indeed%20a%20prime%20or%201.&text=A%20prime%20factor%20is%20not,since%207%3E%E2%88%9A14.
# https://proofwiki.org/wiki/Composite_Number_has_Prime_Factor_not_Greater_Than_its_Square_Root


def prime_factors(n):
    """Returns all the prime factors of a positive integer"""
    factors = set()
    d = 2
    while n > 1:
        while n % d == 0:
            factors.add(d)
            n //= d
        # can make this d+2 if 2 is iterated over separately as all other prime factors are odd
        d = d + 1

    return factors


# pfs = prime_factors(number)
pfs = prime_factors(8)
print(max(pfs))
