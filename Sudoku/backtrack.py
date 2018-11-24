
import input
import graph_basic
import arc_consistency
import forward_checking
import time


def backtrack(sudoku, domain, graph, index, filter):

    if input.solutionComplete(sudoku) == True:
        input.printSudoku(sudoku)
        print("\n\n")
        return

    if filter == 1:
        domain = arc_consistency.arcConsistency(domain, sudoku, graph)
    elif filter == 2:
        domain = forward_checking.forwardChecking(domain, sudoku, graph)

    for i in range(1, 82, 1):
        if domain[i] == []:
            return

    dom = domain[index]
    for d in dom:
        sudoku[index] = d
        if graph_basic.constriantCheck(d, index, graph, sudoku) == True:
            backtrack(sudoku, domain, graph, index+1, filter)
        sudoku[index] = 0




inputSudoku = input.takeInput()
#domain = input.domainConstruction(inputSudoku)
domain = input.naiveDomainConstruction(inputSudoku)
graph = graph_basic.graphConstruction(graph_basic.columnStart, graph_basic.rowStart, graph_basic.squareStart)


startTime = time.time()

#print("\n\n")
backtrack(inputSudoku, domain, graph, 1, 2)

print("\nExecution time:", time.time()-startTime, "seconds")
