m = 4
n = 4

mat = [
    [0 ,1 ,2 ,3 ],
    [4 ,5 ,6 ,7 ],
    [8 ,9 ,10,11],
    [12,13,14,15]
]

def to_coords(num):
    return num // m, num % n

def binarysearch(mat, val, start, end):
    if start == end:
        start_x, start_y = to_coords(start)
        if mat[start_x][start_y] != val:
            return None
        else:
            return start_x, start_y
    
    mid = (start + end) // 2
    mid_x, mid_y = to_coords(mid)
    mat_val = mat[mid_x][mid_y]

    if mat_val == val:
        return mid_x, mid_y
    elif mat_val > val:
        return binarysearch(mat, val, start, mid)
    elif mat_val < val:
        return binarysearch(mat, val, mid + 1, end)

def mat_search():
    # bi>ary search with a translation function for accessing the matrix
    result = binarysearch(mat, 0, 0, m * n - 1)
    print(result)

if __name__ == "__main__":
    mat_search()
    

    
