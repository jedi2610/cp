from collections import Counter
import numpy as np


def my_answer():
    start = 387638
    end = 919123

    passwords = np.asarray(
        list(map(list, map(str, range(start, end)))), dtype=int)
    for i in range(5):
        passwords = passwords[passwords[:, i] <= passwords[:, i + 1]]
    valid_passwords = np.array([], dtype=int).reshape(0, 6)
    for i in range(5):
        valid_passwords = np.r_[valid_passwords,
                                passwords[passwords[:, i] == passwords[:, i + 1]]]
    valid_passwords = np.unique(valid_passwords, axis=0)

    valid_ctr = 0
    for password in iter(map(dict, map(Counter, valid_passwords))):
        for occurrence in password.values():
            if occurrence == 2:
                valid_ctr += 1
                break


# Much more elegant solution
def dvrzero_answer():
    potentials = list(map(str, range(387638, 919123)))

    passedfirst = []
    for item in potentials:
        if item == sorted(item):
            passedfirst.append(item)

    passedsecond = []
    for number in passedfirst:
        for digit in number:
            count = number.count(digit)
            if count >= 2:
                passedsecond.append(number)
                break

    passedthird = []
    for number in passedsecond:
        for digit in number:
            count = number.count(digit)
            if count == 2:
                passedthird.append(number)
                break
    print(passedthird)


def count_passwords_part2(constraint):
    def count(current, i):
        if i == 6:
            if current not in constraint:
                return 0
            sizes = list(Counter(str(current)).values())
            return 1 if 2 in sizes else 0
        elif i == 0:
            return sum(count(current * 10 + d, i + 1) for d in range(1, 10))
        return sum(count(current * 10 + d, i + 1) for d in range(current % 10, 10))
    return count(0, 0)


# Not very elegant but works
if __name__ == "__main__":
    my_answer()
    dvrzero_answer()
    print(count_passwords_part2(range(387638, 919123 + 1)))
