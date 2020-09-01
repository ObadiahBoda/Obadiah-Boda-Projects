import pygame
from Sudoku import solve, print_board
from copy import deepcopy
import time

pygame.font.init()

font = pygame.font.Font("freesansbold.ttf", 24)

height = 50
width = 50
screen = pygame.display.set_mode((height*9,width*9))

board = [[0, 7, 0, 0, 2, 0, 0, 0, 5],
         [0, 6, 0, 0, 0, 0, 7, 0, 0],
         [5, 0, 0, 0, 4, 0, 0, 0, 0],
         [0, 1, 3, 0, 0, 0, 0, 0, 0],
         [6, 0, 0, 0, 5, 0, 0, 0, 2],
         [2, 5, 0, 0, 3, 6, 1, 9, 0],
         [0, 4, 0, 0, 0, 0, 0, 0, 6],
         [7, 2, 0, 4, 9, 0, 0, 5, 1],
         [8, 0, 0, 0, 0, 0, 0, 0, 3]]





def draw_board(width, height):
    screen.fill((255, 255, 255))
    for i in range(1, 9):
        if (i) % 3 == 0:
            pygame.draw.line(screen, (0, 0, 255), (0, i * height), (width * 9, i * height), 4)
            pygame.draw.line(screen, (0, 0, 255), (i * width, 0), (i * width, height * 9), 4)
        else:
            pygame.draw.line(screen, (0, 0, 255), (0, i * height), (width * 9, i * height), 2)
            pygame.draw.line(screen, (0, 0, 255), (i * width, 0), (i * width, height * 9), 2)


def hard_numbers(board, width, height):
    for i in range(9):
        for j in range(9):
            if board[j][i] > 0 and board[j][i] < 10:
                value = font.render(str(board[j][i]), True, (0, 0, 0))
                screen.blit(value, (i * height + 20, j * width + 15))
            if board[j][i] > 10:
                value = font.render(str(board[j][i] - 10), True, (100, 100, 100))
                screen.blit(value, (i * height + 20, j * width + 15))

def confirm(y,x,width,height,bo,board):
    box_x = x // width
    box_y = y // height
    if board[box_y][box_x] - 10 == bo[box_y][box_x]:
        board[box_y][box_x] += -10

def draw_select(x, y):
    box_x = x // width
    box_y = y // height
    pygame.draw.line(screen, (255, 0, 0), (box_x * width, box_y * height), (box_x * width, (box_y + 1) * height), 3)
    pygame.draw.line(screen, (255, 0, 0), (box_x * width, box_y * height), ((box_x + 1) * width, box_y * height), 3)
    pygame.draw.line(screen, (255, 0, 0), ((box_x + 1) * width, (box_y + 1) * height),
                     (box_x * width, (box_y + 1) * height), 3)
    pygame.draw.line(screen, (255, 0, 0), ((box_x + 1) * width, (box_y + 1) * height),
                     ((box_x + 1) * width, box_y * height), 3)

def update(height,width,y,x,board):
    screen.fill((255,255,255))
    draw_board(width,height)
    hard_numbers(board,width,height)
    draw_select(x,y)
    pygame.display.update()

# draw cols,rows
def main(board):
    bo = deepcopy(board)
    solve(bo)
    pygame.display.set_caption("Sudoku")
    pos = [-51,-51]
    update(height,width,pos[1],pos[0],board)

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                pos = pygame.mouse.get_pos()
                update(height,width,pos[1],pos[0],board)
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_DELETE:
                    update(height,width,-51,-51,board)
                if event.key == pygame.K_RETURN:
                    confirm(pos[1],pos[0],width,height,bo,board)
                    update(height,width,pos[1],pos[0],board)
                if event.key == pygame.K_1 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 11
                    update(height, width, pos[1], pos[0], board)
                if event.key == pygame.K_2 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 12
                    update(height, width, pos[1], pos[0], board)
                if event.key == pygame.K_3 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 13
                    update(height, width, pos[1], pos[0], board)
                if event.key == pygame.K_4 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 14
                    update(height, width, pos[1], pos[0], board)
                if event.key == pygame.K_5 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 15
                    update(height, width, pos[1], pos[0], board)
                if event.key == pygame.K_6 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 16
                    update(height, width, pos[1], pos[0], board)
                if event.key == pygame.K_7 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 17
                    update(height, width, pos[1], pos[0], board)
                if event.key == pygame.K_8 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 18
                    update(height, width, pos[1], pos[0], board)
                if event.key == pygame.K_9 and (board[pos[1] // height][pos[0] // width] < 1 or board[pos[1] // height][pos[0] // width] > 9):
                    board[pos[1] // height][pos[0] // width] = 19
                    update(height, width, pos[1], pos[0], board)


main(board)
