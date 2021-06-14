from queue import Queue


def neighbors(visited, matrix, i, j, h, w):
    nei = []
    if(i > 0):
        if(matrix[i-1][j] == 1 and not visited[i - 1][j]):
            nei.append((i-1, j))
    if(i < h - 1):
        if(matrix[i+1][j] == 1 and not visited[i + 1][j]):
            nei.append((i+1, j))
    if(j > 0):
        if(matrix[i][j-1] == 1 and not visited[i][j - 1]):
            nei.append((i, j-1))
    if(j < w - 1):
        if(matrix[i][j+1] == 1 and not visited[i][j + 1]):
            nei.append((i, j+1))
    
    return nei

def search(matrix, i, j, h, w):


    visited = []
    for a in range(h):
        visited.append([])
        for b in range(w):
            visited[a].append(False)

    q = Queue()

    q.put((i, j))

    
    while(not q.empty()):

        ci, cj = q.get()


        if(ci == 0 or cj == 0 or ci == h - 1 or cj == w - 1):
            return False

        visited[ci][cj] = True

        
        for nei in neighbors(visited, matrix, ci, cj, h, w):
            q.put(nei)
        

    return True
    

def islands(matrix):
    h = len(matrix)
    w = len(matrix[0])

    matrix2 = []
    for i in range(h):
        matrix2.append([])
        for j in range(w):
            matrix2[i].append(0)


    for i in range(h):
        for j in range(w):
            if(matrix[i][j] == 1):
                if(search(matrix, i, j, h, w)):
                    matrix2[i][j] = 1

    for i in range(h):
        for j in range(w):
            if(matrix2[i][j] == 1):
                matrix[i][j] = 0

    return matrix, matrix2

def pprint(matrix):

    for i in matrix:
        print(i)


if __name__ == "__main__":


    matrix = []
    for i in range(6):
        matrix.append([])
        for j in range(6):
            matrix[i].append(0)
    matrix[0][0] = 1
    matrix[1][1] = 1
    matrix[2][2] = 1
    matrix[1][3] = 1
    matrix[1][4] = 1
    matrix[1][5] = 1
    matrix[2][4] = 1
    matrix[3][4] = 1
    matrix[5][5] = 1 
    matrix[3][0] = 1
    matrix[3][1] = 1
    matrix[4][0] = 1
    matrix[5][0] = 1
    matrix[4][2] = 1
    matrix[4][3] = 1

    pprint(matrix)

    matrix, matrix2 = islands(matrix)

    print()

    pprint(matrix)

    print()

    pprint(matrix2)

