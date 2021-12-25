



def swapnums(arr, i, j):
    arr[i] += arr[j]
    arr[j] = arr[i] - arr[j]
    arr[i] -= arr[j]

if __name__ == "__main__":
    
    arr = [0,1,2,3,4]
    swapnums(arr, 0, 1)
    print(arr)
