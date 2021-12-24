

def sparseSearch(start, end, arr, val):
    



    if start <= end:

        
        mid = (start + end) // 2


        if arr[mid] == "":
            while(mid < len(arr)):
                if arr[mid] != "":
                    break
                mid += 1
            if mid == len(arr):
                mid -= 1
                while(mid > -1):
                    if arr[mid] != "":
                        break
                    mid -= 1
            if mid == -1:
                return -1


        if arr[mid] == val:
            return mid
        
        #find the lower bound

        elif val < arr[mid]:

            p1 = mid - 1
            while p1 >= 0:
                if arr[p1] != "":
                    return sparseSearch(start, p1, arr, val)
                p1 -= 1
            return -1
                
        else: 
            p1 = mid + 1
            while p1 < len(arr):
                if arr[p1] != "":
                    return sparseSearch(p1, end, arr, val)
                p1 += 1 
            return -1

    else:
        return -1

if __name__ == "__main__":
    

    arr = [

        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "dad",
        "",
        ""

    ]


    val = "dad"
    print(sparseSearch(0, len(arr), arr, val))



