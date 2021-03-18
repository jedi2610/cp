def isInRange(val, low, high):
    return low <= int(val) <= high


def main():
    file = open("input", "r")
    input = file.readlines()
    input.append('')

    ans1, ans2 = 0, 0
    currentPassport = {}

    for line in input:
        line = line.strip()

        if line:
            for info in line.split():
                key, value = info.split(':')
                currentPassport[key] = value
        else:
            # Part 1
            valid1 = all([field in currentPassport for field in [
                         'byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']])
            # Part 2
            valid2 = True

            if 'byr' not in currentPassport or not isInRange(currentPassport['byr'], 1920, 2002):
                valid2 = False

            if 'iyr' not in currentPassport or not isInRange(currentPassport['iyr'], 2010, 2020):
                valid2 = False

            if 'eyr' not in currentPassport or not isInRange(currentPassport['eyr'], 2020, 2030):
                valid2 = False

            if 'hgt' not in currentPassport:
                valid2 = False
            else:
                val = currentPassport['hgt']
                if val.endswith('cm'):
                    if not(150 <= int(val[:-2]) <= 193):
                        valid2 = False
                elif val.endswith('in'):
                    if not(59 <= int(val[:-2]) <= 76):
                        valid2 = False
                else:
                    valid2 = False

            if 'hcl' not in currentPassport or currentPassport['hcl'][0] != '#' or len(currentPassport['hcl']) != 7:
                valid2 = False

            if 'ecl' not in currentPassport or currentPassport['ecl'] not in ['amb', 'blu', 'gry', 'brn', 'grn', 'hzl', 'oth']:
                valid2 = False

            if 'pid' not in currentPassport or len(currentPassport['pid']) != 9:
                valid2 = False

            if valid1:
                ans1 += 1
            if valid2:
                ans2 += 1
            currentPassport = {}

    print(ans1)
    print(ans2)


if __name__ == "__main__":
    main()
