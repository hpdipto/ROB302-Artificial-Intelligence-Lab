

# [ [ 1, 2, 3,   4, 5, 6,   7, 8, 9],
#   [10,11,12,  13,14,15,  16,17,18],
#   [19,20,21,  22,23,24,  25,26,27],

#   [28,29,30,  31,32,33,  34,35,36],
#   [37,38,39,  40,41,42,  43,44,45],
#   [46,47,48,  49,50,51,  52,53,54],

#   [55,56,57,  58,59,60,  61,62,63],
#   [64,65,66,  67,68,69,  70,71,72],
#   [73,74,75,  76,77,78,  79,80,81]
# ]

import math



columnStart = [0, 1, 10, 19, 28, 37, 46, 55, 64, 73]
rowStart = [9, 1, 2, 3, 4, 5, 6, 7, 8]
squareStart = [0, 1, 4, 7, 28, 31, 34, 55, 58, 61]

#constructing the edges
def graphConstruction(columnStart, rowStart, squareStart):
    graph = [[]]
    for index in range(1, 82, 1):
        connected = list()

        #connecting columns
        column = columnStart[math.ceil(index/9)]
        for col in range(column, column+9, 1):
            if col != index:
                connected.append(col)

        #connecting rows
        row = rowStart[index%9]
        for rw in range(row, row+73, 9):
            if rw != index:
                connected.append(rw)

        #connecting squares
        square = squareStart[ math.ceil(row/3) + (math.ceil((math.ceil(index/9))/3)-1) * 3 ]    #need deep thinking :)  square value from 1-9
        for sq in range(square, square+3, 1):
            if sq != index:
                connected.append(sq)
        for sq in range(square+9, square+9+3, 1):
            if sq != index:
                connected.append(sq)
        for sq in range(square+18, square+18+3, 1):
            if sq != index:
                connected.append(sq)

        graph.append(connected)

    return graph



def constriantCheck(value, index, graph, inputSudoku):
    lst = graph[index]
    for i in lst:
        if inputSudoku[i] == value:
            return False
    return True
