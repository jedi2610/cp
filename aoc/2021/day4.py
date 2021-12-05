def checkBoard(board):

    # check rows
    for i in range(0, 25, 5):
        if all(board[i: i+5]):
            return True

    # check columns
    for i in range(5):
        if all(board[i::5]):
            return True

    return False

def sumBoard(board, mask):

    boardSum = 0
    for i, j in zip(board, mask):
        if j == 0:
            boardSum += i

    return boardSum

def solve(nums, boards):
    mask = [[0 for _ in range(25)] for _ in range(len(boards))]
    boardWin = [0 for _ in range(len(boards))]
    part1, part2, done = None, None, False

    for num in nums:
        for i, board in enumerate(boards):
            if num not in board:
                continue
            mask[i][board.index(num)] = 1
            if (checkBoard(mask[i])):
                boardWin[i] = 1
                if (part1 is None):
                    boardSum = sumBoard(board, mask[i])
                    part1 = num * boardSum
                # eventually all boards will win
                if all(boardWin):
                    done = True
                    boardSum = sumBoard(board, mask[i])
                    part2 = num * boardSum
                    break
        if done:
            break

    print(f"Part 1: {part1}")
    print(f"Part 2: {part2}")


if __name__ == '__main__':
    file = open("aoc/2021/inputs/day4", "r")
    nums = list(map(int, file.readline().strip().split(',')))
    boards = []
    for board in file.read().strip().split('\n\n'):
        X = []
        for line in board.split('\n'):
            for num in line.split(' '):
                if num != "":
                    X.append(int(num.strip()))
        assert len(X) == 25
        boards.append(X)

    solve(nums, boards)
