


# get a quick upper bound on the size of the array
def expand(lower, upper, obj):

    if obj.elementAt(upper) == -1:
        return upper
    elif obj.elementAt(upper) != -1:
        return expand(upper, upper * 2, obj)
    
    
# find the exact point where the array ends
def narrow(lower, upper, obj):
    #find the first value that is not -1
    mid = (lower + upper) // 2
    #if less than mid, go left, else go right
    #base case

    if obj.elementAt(mid + 1) == -1 and obj.elementAt(mid) != -1:
        # we found the last index, return mid
        return mid
    elif obj.elementAt(mid) == -1:
        return narrow(lower, mid - 1, obj)
    elif obj.elementAt(mid) != -1:
        return narrow(mid + 1, upper, obj)

def search(start, end, obj, val):
    
    if end >= start:

        mid = (end + start) // 2
        
        if obj.elementAt(mid) == val:
            return mid
        elif obj.elementAt(mid) > val:
            return search(start, mid - 1, obj, val)
        elif obj.elementAt(mid) < val:
            return search(mid + 1, end, obj, val)
    else:
        return -1


class listy():
    def __init__(self, li):
        self._list = li
    
    def elementAt(self, i):
        if i < len(self._list):
            return self._list[i]
        else:
            return -1



if __name__ == "__main__":

    li = [1,2,3,4,5,6,7,8,9,10]
    val = 1

    obj = listy(li)

    upperBound = expand(0, 1, obj)
    last = narrow(upperBound // 2, upperBound, obj)
    ind = search(0, last, obj, val) 
    print(ind)
