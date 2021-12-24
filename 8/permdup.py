from copy import copy


def sub(s, n):
    
    # get all substrings of the string
    if(len(s) == 1):
        return s 
    
    return [i for i in s if i != n] 


def cat(s, n):

    li = []
    li.append(s + n)
    for i in range(len(s)):
        if n not in s:
            tl = s[:i]
            tl += n
            tl += s[i:]

            li.append(tl)

    return li


def perm(s, l, d):


    if l == 1:
        endingList = []

        for key, value in d.items():
            if d[key] != 0:

                copyDict = copy(d)
                copyDict[key] -= 1
                copy_s = s
                copy_s += key

                endingList.append(s + key)

        return endingList


    # for each letter in dict, if it is not 0, return s + it

    returnList = []

    for key, value in d.items():
        
        if d[key] != 0:
            copyDict = copy(d)
            copyDict[key] -= 1
            copy_s = s
            copy_s += key
            [returnList.append(l) for l in perm(copy_s, l - 1, copyDict)]

    # return the previous value plus all of the perms
    return returnList


# append current letter,
# append three of each following letter

def letterCounter(s):
    d = dict()

    for letter in s:
        if letter not in d:

            d[letter] = 1
        else:
            d[letter] += 1

    return d


if __name__ == "__main__":

    s = 'abbd'
    d = letterCounter(s)
    print(perm("", len(s),  d))

