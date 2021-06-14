
def putQueen(board, pos):
    board[pos[0]][pos[1]] = 'q'
    return board

def checkPlacement(pos1, pos2):
    if(pos1[0] == pos2[0] or pos1[1] == pos2[1]):
        return False
    elif(pos1[0] - pos2[0] == pos1[1] - pos2[1]):
        return False
    elif(pos1[0] - pos2[0] == -1 * (pos1[1] - pos2[1])):
        return False
    return True

def pprint(board, states):

    for i in range(8):
        board[i][states[i]] = 'q'

    for i in range(8):
        for j in range(8):
            if(j == states[i]):
                print('q', end='')
            else:
                print('+', end='')
        print()

    print()

def checkNoConflict(posList, pos):
    #list posList
    #pos pos for next pos
    #returns true if there are no conflicts
    posRow = len(posList) 

    for i in range(len(posList)):
        posPos = (posRow, pos)
        listPos = (i, posList[i])

        if not checkPlacement(posPos, listPos):
            return False

    return True

def allPossibleStates(row, currentList = []):
    
    if len(currentList) == 0:
        return [[i] for i in range(8)]
    else:
        return [[i] for i in range(8) if checkNoConflict(currentList, i)]

def recursiveSearch(n):

    if(n == 0):
        return allPossibleStates(0) 

    prev_list = recursiveSearch(n - 1)

    new_list = []

    for item in prev_list:
        new_nums = allPossibleStates(n, item)
        for num in new_nums:
            new_list.append(item + num)
    
    return new_list

    
if __name__ == "__main__":

    board = []
    for i in range(8):
        board.append([])
        for j in range(8):
            board[i].append('e')

    print(board) 


    s = recursiveSearch(7)

    [pprint(board, i) for i in s]

    
