

def median_of_three(arr):
    bottom = 0
    top = len(arr) - 1
    mid = (top // 2)

    s = sorted([arr[bottom], arr[top], arr[mid]])

    arr[bottom] = s[0]
    arr[mid] = s[1]
    arr[top] = s[2]

def swap(i, j, arr):
    temp = arr[j]
    arr[j] = arr[i]
    arr[i] = temp


def quicksort(left, right, arr):
    median = partition(left, right, arr)

    if(left < median - 1):
        quicksort(left, median - 1, arr)
    elif(median < right):
        quicksort(median, right, arr)


def partition(left, right, arr):

    median = arr[(left + right) // 2]

    while(left <= right):


        while(arr[left] < median):
            left += 1

        while(arr[right] > median):
            right -= 1


        if(left <= right):
            swap(left, right, arr)
            left += 1
            right -= 1
            
    return left 

if __name__ == "__main__":


    arr = [2,6,5,3,4,7,1,0,8]

    median_of_three(arr)


    quicksort(0, len(arr) - 1, arr)
    
    print(arr)
