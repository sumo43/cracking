import numpy as np

board = []

def neighbors(board, point, col):

    li = []

    for i in range(-1, 2):
        for j in range(-1, 2):
            if((i, j) != point and (0 <= i < len(board)) and (0 <= j < len(board[0]))):
                if(board[i][j] == col):
                    li.append((i, j))

    return li

def fill(board, point, origColor, color):










    



if __name__ == "__main__":



    
    
