def sumswap(arr1, arr2):
    print(sum(arr1))
    print(sum(arr2))

if __name__ == '__main__':
    arr1 = [8,1,2,1,1,2]
    arr2 = [3,4,1,3]
    hash1 = dict()
    hash2 = dict()
    # find 2 numbers such that the difference in the numbers is half the difference of the sums
    diffsum = abs(sum(arr1) - sum(arr2))
    num1 = None
    num2 = None
    for item in arr1:
        hash1[item] = item
    for item in arr2:
        hash2[item] = item
    for item in arr1:
        target = (diffsum // 2) + item
        target2 = -(diffsum // 2) + item
        print(target)
        print(target2)
        if target in hash2:
            num1 = item
            num2 = target
            break
        if target2 in hash2:
            num1 = item
            num2 = target
            break
    print(num1)
    print(num2)
