import graph_basic


#basic operations regarding solving like taking input, printing output, domain constrution


def takeInput():
    file = open("input.txt", "r")
    inputSudoku = [0]
    for line in file:
    #for i in range(1, 18, 1):
        #inputStr = input()
        inputStr = line
        for s in inputStr:
            if s == "\n":
                continue
            if s == ".":
                inputSudoku.append(0)
            else:
                inputSudoku.append(int(s))
    return inputSudoku


def printSudoku(sudoku):
    for i in range(1, 82, 1):
        print(sudoku[i], end=" ")
        if i % 3 == 0 and i%9 != 0:
            print("", end="| ")
        if i % 9 == 0:
            print("\n", end="")
        if i % 27 == 0 and i != 81:
            print("---------------------\n", end="")


def solutionComplete(sudoku):
    for i in range(1, 82, 1):
        if sudoku[i] == 0:
            return False
    return True



def domainConstruction(inputSudoku):
    domain = [[]]
    for i in range(1, 82, 1):
        domain.append([j for j in range(1, 10, 1)])

    graph = graph_basic.graphConstruction(graph_basic.columnStart, graph_basic.rowStart, graph_basic.squareStart)

    for i in range(1, 82, 1):
        if inputSudoku[i] != 0:
            domain[i] = [inputSudoku[i]]
            filterList = graph[i]
            for lst in filterList:
                if inputSudoku[i] in domain[lst]:
                    domain[lst].remove(inputSudoku[i])
    return domain


def naiveDomainConstruction(inputSudoku):
    domain = [[]]
    for i in range(1, 82, 1):
        if inputSudoku[i] == 0:
            domain.append([j for j in range(1, 10, 1)])
        else:
            domain.append([inputSudoku[i]])
    return domain



# input = takeInput()
# printSudoku(input)

# file = open("input.txt", "r")
# for line in file:
#     print(line, end="#")
