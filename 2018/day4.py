def main():
    file = open("input", "r")
    ins = {}
    lines = open("input", "r").read().split('\n')
    lines.sort()
    print(lines)
    for line in file.readlines():
        info = line.split()
        month, date = map(int, info[0].split('-')[1:])
        hour, min = info[1].split(':')
        hour = int(hour)
        min = int(min[:-1])
        i = info[-1]
        if i == "up":
            doing = i
        elif i == "asleep":
            doing = i
        else:
            doing = info[-3]
        try:
            ins[(month, date)].update({(hour, min): doing})
        except KeyError:
            ins[(month, date)] = {}
            ins[(month, date)].update({(hour, min): doing})

    listOfDates = sorted(ins)
    guardInfo = {}
    latestMin, latestId = (0, 0)
    for (month, date) in listOfDates:
        # iterating through each day
        listOfTimes = sorted(ins[month, date].items())
        for (hour, min), doing in listOfTimes:
            # iterating through each hour
            if doing == "up":
                for i in range(latestMin, min):
                    try:
                        guardInfo[latestId][i] += 1
                    except KeyError:
                        guardInfo[latestId][i] = 0
            elif doing == "asleep":
                latestMin = min
            else:
                id = int(doing[1:])
                if id not in guardInfo.keys():
                    guardInfo[id] = {}
                latestId = id

            latestMin = min

    high = -1
    mi = -1
    id = 9343
    tot = 1
    for key, info in guardInfo.items():
        for time, value in info.items():
            if (value > high and (time * key) < tot):
                high = value
                mi = time
                id = key

    print(mi, id)

    # li = []
    # for key, info in guardInfo.items():
    #     try:
    #         li.append(max(info, key=lambda x: info[x]))
    #     except ValueError:
    #         pass
    # print(max(li))
    # print(sorted(guardInfo[1091].items()))
    # print(sorted(guardInfo[2137].items()))
    # print(id, mi, id*mi)


if __name__ == "__main__":
    main()
