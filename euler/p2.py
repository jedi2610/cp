# prev, cur = 0, 1
# total = 0
# while True:
#     if cur >= 4000000:
#         break
#     if cur % 2 == 0:
#         total += cur
#     prev, cur = cur, prev + cur


# def calcE():
#     x = y = 1
#     sum = 0
#     while (sum < 4000000):
#         sum += (x + y)
#         x, y = x + 2 * y, 2 * x + 3 * y
#     return sum

# 4613732
cur = 34
sum = 2 + 8 + 34
while cur <= 4000000:
    sum += int(cur)
    cur *= 4.23

print(sum)

# print(calcE())
# print(total)
