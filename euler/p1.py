def ap(limit: int, n: int) -> int:
    # n = no of terms = (limit/n)
    # say limit is 1000 and n is 3 and int(1000/3) = 333
    # so there are 333 terms b/w 3 and 1000 that are
    # divisible by 3 if i was to include 0 to the AP then i should
    # a 1 to the number of terms because i'm adding a 0 to the start
    # formula for AP when the last term is not known =>
    # S(n) = n/2 ((2*a) + (n-1)*d) where n is number of terms,
    # a is the first term and d is the common difference
    # the formula for AP if the last term is known =>
    # S(n) = n/2 (a+l) where n is no of terms, a is the first term and l is the last term
    # a(n) = nth term of the progresstion is => a + (n-1)d
    terms = int(limit/n)
    # this is a simplified version because here a=d=n
    sumTerms = terms * (n * (1 + terms))
    # i divide by 2 before returning the sum cause the above line is a little clumsy
    return int(sumTerms/2)


def sum_all_multiples(lim: int) -> int:
    # the arithmetic progresstion way
    sumOfMultiples = 0
    for num in [3, 5]:
        sumOfMultiples += ap(lim, num)
    sumOfMultiples -= ap(lim, 15)
    return sumOfMultiples


# 1000 - 1 because the question is all the numbers below 1000 so...
print(sum_all_multiples(1000 - 1))
