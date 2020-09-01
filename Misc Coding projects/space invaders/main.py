import pygame
import random
import math

# initialize pygame
pygame.init()

# creates screen
screen = pygame.display.set_mode((800, 600))

# title and Icon
pygame.display.set_caption("Space Invaders")
icon = pygame.image.load("spaceship.png")
pygame.display.set_icon(icon)
backGroundImg = pygame.image.load("space.jpg")

# player
playerImg = pygame.image.load("spaceship1.png")
playerX = 370
playerY = 480
playerSpdX = 0
playerSpdY = 0
spd = 10

# laser
laserImg = pygame.image.load("laser.png")
laserX = 0
laserY = 800
laserSpdY = spd * 2
laser_state = "ready"

# enemy
enemyImg = []
number_of_enemys = 6

enemyX = []
enemyY = []
enemySpdY = []
enemySpdX = []
prevY = []

for i in range(number_of_enemys):
    enemyImg.append(pygame.image.load("alien.png"))
    enemyX.append(random.randint(0, 720))
    enemyY.append(random.randint(0, 100))
    enemySpdY.append(0)
    enemySpdX.append(spd)
    prevY.append(0)

# score
score_value = 0
font = pygame.font.Font("freesansbold.ttf", 32, )
font2 = pygame.font.Font("freesansbold.ttf", 64, )

textX = 10
textY = 10


def show_score(x, y):
    score = font.render("Score : " + str(score_value), True, (100, 100, 100))
    screen.blit(score, (x, y))


def player(x, y):
    screen.blit(playerImg, (x, y))


def laser(x, y):
    global laser_state
    global laserX
    global laserY
    laserX = x + 24
    laser_state = "fire"
    laserY = y + 10

    screen.blit(laserImg, (x + 16, y + 24))


def enemy(x, y, i):
    screen.blit(enemyImg[i], (x, y))


def laser_enemy_collision(xenemy, yenemy, xlaser, ylaser):
    distance = math.sqrt(pow(xenemy + 16 - xlaser + 8, 2) + pow(yenemy + 16 - ylaser + 8, 2))
    if distance < 40:
        return True
    else:
        return False


def game_over():
    global  running
    restart = True
    while restart:
        screen.blit(backGroundImg, (0, 0))
        txt = font2.render("Press Spacebar", True, (255, 255, 255))
        txt2 = font2.render("To Continue!", True, (255, 255, 255))
        screen.blit(txt, (160, 200))
        screen.blit(txt2, (200, 300))
        pygame.display.update()

        for events in pygame.event.get():
            if events.type == pygame.KEYDOWN:
                if events.key == pygame.K_SPACE:
                  restart = False

            if events.type == pygame.QUIT:
                running = False




# game loop
running = True
while running:
    screen.blit(backGroundImg, (0, 0))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                playerSpdX += -spd
            if event.key == pygame.K_RIGHT:
                playerSpdX += spd
            if event.key == pygame.K_UP:
                playerSpdY += -spd
            if event.key == pygame.K_DOWN:
                playerSpdY += spd
            if event.key == pygame.K_SPACE and laser_state == "ready":
                laser(playerX, playerY)

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                playerSpdX += spd
            if event.key == pygame.K_RIGHT:
                playerSpdX += -spd
            if event.key == pygame.K_UP:
                playerSpdY += spd
            if event.key == pygame.K_DOWN:
                playerSpdY += -spd

    # RGB

    playerX += playerSpdX
    playerY += playerSpdY

    laserY += -laserSpdY

    if playerX > 730:
        playerX = 730
    if playerX < 0:
        playerX = 0
    if playerY > 530:
        playerY = 530
    if playerY < 0:
        playerY = 0

    for i in range(number_of_enemys):
        if enemyX[i] > 730 or enemyX[i] < 0:
            enemySpdX[i] = 0
            enemySpdY[i] = spd

        if enemyY[i] > prevY[i] + 50 and enemyX[i] > 730:
            enemySpdX[i] = -spd
            enemySpdY[i] = 0
            prevY[i] = enemyY[i]

        elif enemyY[i] > prevY[i] + 50 and enemyX[i] < 0:
            enemySpdX[i] = spd
            enemySpdY[i] = 0
            prevY[i] = enemyY[i]

        elif enemyY[i] > prevY[i] + 50:
            enemySpdX[i] = spd
            enemySpdY[i] = 0
            prevY[i] = enemyY[i]

        collision = laser_enemy_collision(enemyX[i], enemyY[i], laserX, laserY)
        if collision:
            enemyX[i] = random.randint(0, 720)
            enemyY[i] = random.randint(0, 100)
            prevY[i] = enemyY[i]
            laser_state = "ready"
            laserX = -100
            score_value += 10

        if enemyY[i] > 600:
            screen.blit(backGroundImg, (0, 0))
            pygame.display.update()
            game_over()
            for j in range(number_of_enemys):
                enemyX[j] = random.randint(0, 720)
                enemyY[j] = random.randint(0, 100)
                prevY[j] = enemyY[j]
            playerSpdY = 0
            playerSpdX = 0

        enemyX[i] += enemySpdX[i]
        enemyY[i] += enemySpdY[i]
        enemy(enemyX[i], enemyY[i], i)

    if laser_state == "fire":
        screen.blit(laserImg, (laserX, laserY - spd))
        if laserY < 0:
            laser_state = "ready"

    show_score(textX, textY)
    player(playerX, playerY)
    pygame.display.update()
