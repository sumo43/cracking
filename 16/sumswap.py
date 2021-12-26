def sumswap(arr1, arr2):
    print(sum(arr1))
    print(sum(arr2))

if __name__ == '__main__':
    arr1 = [4,1,2,1,1,2]
    arr2 = [3,6,3,3]
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
        if target in hash2:
            print(arr1, target)
            break
        if target2 in hash2:
            print(arr1, target)

    for i, ind1 in enumerate(arr1):
        for j, ind2 in enumerate(arr2):
            if abs(ind1 - ind2) * 2 == diffsum:
                num1 = ind1
                num2 = ind2
                break
    print((num1, num2))
