# draw grid


board = [[0, 7, 0, 0, 2, 0, 0, 0, 5],
         [0, 6, 0, 0, 0, 0, 7, 0, 0],
         [5, 0, 0, 0, 4, 0, 0, 0, 0],
         [0, 1, 3, 0, 0, 0, 0, 0, 0],
         [6, 0, 0, 0, 5, 0, 0, 0, 2],
         [2, 5, 0, 0, 3, 6, 1, 9, 0],
         [0, 4, 0, 0, 0, 0, 0, 0, 6],
         [7, 2, 0, 4, 9, 0, 0, 5, 1],
         [8, 0, 0, 0, 0, 0, 0, 0, 3]]


def print_board(bo):
    for i in range(len(bo)):
        if i % 3 == 0 and i != 0:
            print("- - - - - - - - - - - -")
        for j in range(len(bo[0])):
            if j % 3 == 0 and j != 0:
                print(" | ", end="")
            print(str(bo[i][j]) + " ", end="")
        print("")


def find_empty(bo):
    for i in range(len(bo)):
        for j in range(len(bo[0])):
            if bo[i][j] == 0:
                return (i, j)
    return False


def valid(pos, bo, num):
    # row check
    for i in range(len(bo[0])):
        if bo[pos[0]][i] == num and pos[1] != i:
            return False

    # collumn
    for i in range(len(bo[0])):
        if bo[i][pos[1]] == num and pos[0] != i:
            return False

    # square
    box_x = pos[1] // 3
    box_y = pos[0] // 3

    for i in range(box_y*3,box_y*3+3):
        for j in range(box_x*3,box_x*3+3):
            if bo[i][j] == num and (i,j) != pos:
                return False

    return True


def solve(bo):

    find = find_empty(bo)
    if not find:
        return True
    else:
        row, column = find

    for i in range(1,10):
        if valid((row,column),bo , i):
            bo[row][column] = i
            if solve(bo):
                return True
            bo[row][column] = 0
    return False

#print_board(board)
#solve(board)
#print("")
#print_board(board)