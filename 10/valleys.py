arr = [5,3,1,2,3,4]

def swap(i, j, arr):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

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

arr.sort()
arr.reverse()

if len(arr) % 2 == 1:
    mid = len(arr) // 2 + 1
else:
    mid = len(arr) // 2
high = arr[:mid]
low = arr[mid:]

low.reverse()

new = []
j = 0

lenlow = len(low) - 1

for i in range(len(low)):
    new.append(high[i])
    new.append(low[lenlow -i])
if len(arr) % 2 == 1:
    new.append(high[len(high) - 1])
