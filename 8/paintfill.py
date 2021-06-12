import numpy as np

board = []
a = 0
b = 0

def neighbors(point, col):

    li = []

    for i in range(-1, 2):
        for j in range(-1, 2):
            new_i = i + point[0]
            new_j = j + point[1]
            if((0 <= new_i < len(board)) and (0 <= new_j < len(board[0]))):
                if(board[new_i][new_j] == col):
                    li.append((new_i, new_j))

    return li

def fill(point, origColor, color):

    i, j = point
    board[i][j] = color

    for nei in neighbors(point, origColor):
        fill(nei, origColor, color) 


def pprint():
    for i in range(a):
        for j in range(b):
            print(board[i][j], end=" ")
        print('')
    

if __name__ == "__main__":
    a = 5
    b = 5

    for i in range(a):
        board.append([])
        for j in range(b):
            board[i].append(0)

    fill((0,0), 0, 1)

    pprint()



    
    
