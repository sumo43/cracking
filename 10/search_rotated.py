
def startSearch(lower, upper, arr, val):
    #find the value smaller than value 0 of the array

    mid = (lower + upper) // 2
    #if less than mid, go left, else go right
    if arr[mid - 1] > arr[mid]:
        # we found the point of rotation, return the index
        return mid 
    elif arr[mid] < val:
        return startSearch(lower, mid - 1, arr, val)
    elif arr[mid] > val:
        return startSearch(mid + 1, upper, arr, val)


def search(start, end, arr, val):
    
    if end >= start:

        mid = (end + start) // 2

        sml_mid = mid % len(arr) 

        
        if arr[sml_mid] == val:
            return sml_mid
        elif arr[sml_mid] > val:
            return search(start, mid - 1, arr, val)
        elif arr[sml_mid] < val:
            return search(mid + 1, end, arr, val)
    else:
        return -1



def rotatedSearch(arr, val):
    #O(2logn), so O(logn)
    
    #amount by which to rotate
    i = startSearch(0, len(arr) - 1, arr, val)

     
    return search(i, len(arr) - 1 + i, arr, val)
     



if __name__ == "__main__":


    arr = [15,16,19, 20, 25, 1, 3, 4, 5, 7, 10, 14]   
    
    print(rotatedSearch(arr, 20))
