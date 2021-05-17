metadata = []
input = []


def processNode(pos):
    global metadata, input

    noChild, noMetadata = input[pos], input[pos+1]
    count = offset = value = 0
    childValue = []
    listOfData = []

    while count < noChild:
        childOffset, nodeValue = processNode(pos+2+offset)
        offset += childOffset
        childValue.append(nodeValue)
        count += 1

    for i in range(pos+2+offset, pos+2+offset+noMetadata):
        listOfData.append(input[i])
    metadata.extend(listOfData)

    if noChild == 0:
        for i in range(pos+2+offset, pos+2+offset+noMetadata):
            value += input[i]
    else:
        for i in listOfData:
            try:
                value += childValue[i-1]
            except IndexError:
                continue

    offset += 2+noMetadata
    return offset, value


def main():
    global metadata, input
    file = open('input', 'r')
    input = list(map(int, file.readline().split()))
    _, nodeValue = processNode(0)
    print(sum(metadata))
    print(nodeValue)


if __name__ == "__main__":
    main()
