class Node:

    def __init__(self, name, parent: "Node" = None):
        self.name = name
        self.parent = parent

    def __repr__(self):
        try:
            return self.name + " " + self.parent.name
        except (TypeError, AttributeError):
            return self.name + " None"

    def __eq__(self, other):
        if not isinstance(other, Node):
            return False
        return self.name == other.name

    def __cmp__(self, other):
        if not isinstance(other, Node):
            return False
        return self.name == other.name


def getScore(listOfNodes: list):

    score = 0
    for node in listOfNodes:
        while node.parent != None:
            score += 1
            node = node.parent
    return score


def main():

    inputFile = open("input.txt", "r")
    input = inputFile.readlines()
    listOfNodes = list()
    indexes = dict()

    for line in input:
        parent, child = line.strip().split(")")

        if parent not in indexes.keys():
            listOfNodes.append(Node(parent, None))
            indexes[parent] = len(listOfNodes) - 1

        parentNode = listOfNodes[indexes.get(parent)]

        node = Node(child, parentNode)
        pos = indexes.get(child)
        if (child not in indexes.keys()):
            listOfNodes.append(node)
            indexes[child] = len(listOfNodes) - 1
        elif listOfNodes[pos].parent != parentNode:
            pos = indexes.get(child)
            node = listOfNodes[pos]
            node.parent = parentNode
            listOfNodes[pos] = node

    print(getScore(listOfNodes))

    myNode = listOfNodes[indexes.get("YOU")]
    sanNode = listOfNodes[indexes.get("SAN")]
    myParents = []
    sanParents = []

    while True:
        myNode = myNode.parent
        sanNode = sanNode.parent

        myParents.append(myNode)
        sanParents.append(sanNode)

        if myNode in sanParents:
            print(sanParents.index(myNode) + myParents.index(myNode))
            break
        elif sanNode in myParents:
            print(sanParents.index(sanNode) + myParents.index(sanNode))
            break


if __name__ == "__main__":
    main()
