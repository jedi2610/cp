import math


class Library:
    nBooks = int()
    shippingCapacity = int()
    signupDays = int()
    bookIDs = list()
    daysToScan = int()
    totBookScore = int(0)
    qualityFactor = float(0)

    # Calculates the sum of scores of each book in library
    def calcTotBookScore(self, scoreOfBooks):
        for i in self.bookIDs:
            self.totBookScore += scoreOfBooks[i]

    # Assigning each library a qualityFactor to yeild a higher score
    def calcQualityFactor(self):
        if self.nBooks == 0:
            self.qualityFactor = 0
        else:
            self.qualityFactor = (self.totBookScore) / (self.signupDays)

    # Sorting books based on their scores
    def sortBooks(self, scoreOfBooks):
        self.bookIDs = sorted(
            self.bookIDs, key=lambda x: scoreOfBooks[x], reverse=True)

    def updateValues(self):
        self.nBooks = len(self.bookIDs)
        self.daysToScan = math.ceil(self.nBooks / self.shippingCapacity)

    def __init__(self, nBooks, signupDays, shippingCapacity, bookIDs):
        self.nBooks = nBooks
        self.signupDays = signupDays
        self.shippingCapacity = shippingCapacity
        self.bookIDs = bookIDs


def main(files):
    # Declarations and basic inputs
    input_file = open(files)
    noOfBooks, noOfLibraries, deadline = map(
        int, input_file.readline().split())
    noOfBooks = int(noOfBooks)
    noOfLibraries = int(noOfLibraries)
    deadline = int(deadline)
    scoreOfBooks = list(map(int, input_file.readline().split()))
    isBookAlreadyPresent = [False] * noOfBooks
    libraries = list()
    signupDaysList = list()
    remainingDays = deadline
    i = int(0)
    totScore = int(0)  # Calculate the score of my program
    bookCapacity = int()  # Number of books that can be sent before deadline
    # print(sum(scoreOfBooks))

    # Input for library data
    for i in range(0, noOfLibraries):
        nBooks, signupDays, shippingCapacity = map(
            int, input_file.readline().split())
        if shippingCapacity > nBooks:
            shippingCapacity = nBooks
        nBooks = int(nBooks)
        signupDays = int(signupDays)
        shippingCapacity = int(shippingCapacity)
        bookIDs = list(map(int, input_file.readline().split()))
        libraries.append(Library(nBooks, signupDays,
                                 shippingCapacity, bookIDs))

    # Removing books that are already present and performing some actions on libraries
    for library in libraries:
        # [:] means to create a copy of the same list - list comprehension
        for book in library.bookIDs[:]:
            if isBookAlreadyPresent[book]:
                library.bookIDs.remove(book)
            else:
                isBookAlreadyPresent[book] = True
        library.updateValues()
        library.calcTotBookScore(scoreOfBooks)
        library.calcQualityFactor()
        library.sortBooks(scoreOfBooks)
        if library.nBooks != 0:
            signupDaysList.append(library.signupDays)

    libraries = filter(lambda library: library.qualityFactor != 0, libraries)
    noOfLibraries = len(signupDaysList)
    libraries = sorted(
        libraries, key=lambda Library: Library.qualityFactor, reverse=True)
    i = 0

    while (remainingDays > 0 and i != noOfLibraries):

        # Checking if remainingDays are less than signupDays of library
        print("SDays: {0} TotScore: {1} SC: {3} QF: {2}  RDays: {4} ".format(libraries[i].signupDays,
                                                                             libraries[i].totBookScore, libraries[i].qualityFactor,
                                                                             libraries[i].shippingCapacity, remainingDays))
        if remainingDays - libraries[i].signupDays > 0:
            remainingDays -= libraries[i].signupDays
            bookCapacity = remainingDays * \
                libraries[i].shippingCapacity if libraries[i].daysToScan > remainingDays else len(
                    libraries[i].bookIDs)

            # Updating totScore
            for j in range(0, bookCapacity):
                totScore += scoreOfBooks[libraries[i].bookIDs[j]]

        i += 1
    print("Total Score: ", totScore, files)
    return totScore


if __name__ == "__main__":
    score = int(0)
    filelist = ["a_example.txt", "b_read_on.txt", "c_incunabula.txt",
                "d_tough_choices.txt", "e_so_many_books.txt", "f_libraries_of_the_world.txt"]
    # filelist = ["f_libraries_of_the_world.txt"]
    scorefile = open("score.txt", "w")

    for files in filelist:
        perscore = main(files)
        score += perscore
        scorefile.write(str(f"{files} = {perscore}\n"))

    print("Final Score: ", score)
    scorefile.write(str(score))
    scorefile.close()
