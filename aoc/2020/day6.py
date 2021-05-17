def main():
    file = open("input", "r")
    lines = file.readlines()
    lines.append('')

    p1 = p2 = 0
    anyYes = allYes = None

    for line in lines:
        line = line.strip()
        if line:
            if anyYes is None:
                anyYes = set(line)
            else:
                # Union
                anyYes = anyYes | set(line)
                # anyYes = anyYes.union(set(line))

            if allYes is None:
                allYes = set(line)
            else:
                # Intersection
                allYes = allYes & set(line)
                # allYes = allYes.intersection(set(line))
        else:
            p1 += len(anyYes)
            p2 += len(allYes)
            anyYes = allYes = None

    print(p1)
    print(p2)


if __name__ == "__main__":
    main()
