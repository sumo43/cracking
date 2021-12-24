def swap(i, j, arr):
    temp = arr[j]
    arr[j] = arr[i]
    arr[i] = temp

def radixsort(index,  arr):
    
    for item in li:
        partition(item, arr)

def group(index, start, end, arr):

    while(True):
        a = 0
        for i in range(start, end - 1):
            if(arr[i] > arr[i + 1]):
                swap(i, i + 1, arr)
            
                a += 1
                
        if(a == 0):
            break
    

    
    
        
        
if __name__ == "__main__":
    
    # if the number is less than 0, prepend it with a zero

    arr = [1,12,13,14,23,23,3,4,5,23,1,3]


    group(0, 0, len(arr), arr)

    print(arr)


