maxNum = 0
for i in range(900, 1000):
    for j in range(900, 1000):
        prod = i * j
        num = str(prod)
        if num == num[::-1]:
            # print(prod, i, j)
            maxNum = max(maxNum, prod)

print(maxNum)
