


def sortedMerge(a, b):

    # 0 represents an empty spot in the array here
    cur_a = 0
    cur_b = 0
    buffer = [0 for i in a]
    
    for i in range(len(a)):

        if a[cur_a] != 0 and (cur_b == len(b) or a[cur_a] <= b[cur_b]):
            buffer[i] = a[cur_a]
            cur_a += 1
        else:
            buffer[i] = b[cur_b]
            cur_b += 1

    for i in range(len(buffer)):
        a[i] = buffer[i]

    return a


if __name__ == "__main__":


    a = [1,2,5,6,7, 0, 0, 0]
    b = [3,4,8]

    print(sortedMerge(a, b))
