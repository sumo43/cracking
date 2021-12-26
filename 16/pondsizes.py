def bfs(pond, start):
    counter = 0
    visited = []
    queue = []
    queue.append(start)
    while queue:
        curr = queue.pop(0)
        counter += 1
        visited.append(curr)
        curr_x, curr_y = curr
        # check neighbors
        for i in range(-1, 2):
            for j in range(-1, 2):
                if (curr_x + i) < len(pond) and (curr_x + i) >= 0 and (curr_y + j) < len(pond) and (curr_y + j) >= 0 and (curr_x + i, curr_y + j) not in visited:
                    if pond[curr_x + i][curr_y + j] == 0:
                        queue.append((curr_x + i, curr_y + j))
    for tup in visited:
        x, y = tup
        pond[x][y] = 1
    return counter

def calculate_pond_sizes(pond):
    counts = []
    for i in range(len(pond)):
        for j in range(len(pond)):
            if pond[i][j] == 0:
                counts.append(bfs(pond, (i, j)))
    return counts
if __name__ == "__main__":
    pond = [
    [0, 2, 1, 0],
    [0, 1, 0, 1],
    [1, 1, 0, 1],
    [0, 1, 0, 1]]
    print(calculate_pond_sizes(pond))
