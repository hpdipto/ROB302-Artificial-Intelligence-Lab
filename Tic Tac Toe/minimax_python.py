#tic-tac-toe implementation using minimax algorithm in python

grid = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]


def result(player):
    for i in range(1, 10, 3):
        if grid[i] == grid[i+1] and grid[i+1] == grid[i+2] and grid[i+2] == player:
            return 1
        elif grid[i] == grid[i+1] and grid[i+1] == grid[i+2] and grid[i+2] == int(not player):
            return -1
    for i in range(1, 4, 1):
        if grid[i] == grid[i+3] and grid[i+3] == grid[i+6] and grid[i+6] == player:
            return 1
        elif grid[i] == grid[i+3] and grid[i+3] == grid[i+6] and grid[i+6] == int(not player):
            return -1
    if grid[1] == grid[5] and grid[5] == grid[9] and grid[9] == player:
        return 1
    elif grid[1] == grid[5] and grid[5] == grid[9] and grid[9] == int(not player):
        return -1;
    if grid[3] == grid[5] and grid[5] == grid[7] and grid[7] == player:
        return 1
    elif grid[3] == grid[5] and grid[5] == grid[7] and grid[7] == int(not player):
        return -1
    return 0


def gameOver():
    for i in range(1, 10, 1):
        if grid[i] == -1:
            return False
    return True


xo = ["o", "x"]
def printGrid():
    for i in range(1, 10, 1):
        if grid[i] != -1:
            print(" " + xo[grid[i]], end=' ')
        else:
            print("  ", end=' ')

        if i % 3 != 0:
            print("|", end='')
        else:
            print("")
        if i % 3 == 0 and i != 9:
            print("---+---+---")


def minimax(player, mainPlayer):
    if (result(player) == 0) and (gameOver() == True):
        return 0
    if result(player):
        if player == mainPlayer:
            return -1
        else:
            return 1

    if player == mainPlayer:
        v = -5
        for i in range(1, 10, 1):
            if grid[i] == -1:
                grid[i] = player
                v = max(v, minimax(int(not player), mainPlayer))
                grid[i] = -1
        return v
    else:
        v = 5
        for i in range(1, 10, 1):
            if grid[i] == -1:
                grid[i] = player
                v = min(v, minimax(int(not player), mainPlayer))
                grid[i] = -1
        return v

def play(player):
    v = -5
    for i in range(1, 10, 1):
        if grid[i] == -1:
            grid[i] = player
            v2 = minimax(int(not player), player)
            grid[i] = -1
            if v2 > v:
                v = v2
                move = i
    return move

#main part

option = 1
while option == 1:
    print(" 1.x\n 2.o\nChose your sign:", end = ' ')
    player = int(input())
    if player == 1:
        player = 0
    else:
        player = 1

    print(" 1.CPU first\n 2.Human first\nChose an option:", end = ' ')
    option = int(input())
    if option == 1:
        grid[1] = player
        print("\n")
        print("CPU:")
        printGrid()
    while True:
        print("Enter a grid number[0-9]:", end = ' ')
        option = int(input())
        if grid[option] != -1:
            print("Invalid gird!")
            continue
        grid[option] = int(not player)
        print("Human:")
        printGrid()
        print("\n")

        grid[play(player)] = player
        print("CPU:")
        printGrid()
        print("\n")

        if gameOver() and result(player) == 0:
            print("Match Draw!\n\n")
            break
        if result(player) == 1:
            print("CPU Won!\n\n")
            break
    print("Press 1 to play again, other to exit:", end=' ')
    option = int(input())
    if option != 1:
        break
    for i in range(1, 10, 1):
        grid[i] = -1
