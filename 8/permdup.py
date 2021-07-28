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
    

def perm(s, d):

    if(len(d) == 1):
        st = ""

        for key, value in d.items():
            for i in range(int(value)):
                st += key

        return st


    for key, value in d.items():
        copy_dict = copy(d)

        new_s = s + key


    catLetter = s[0]
    rest = s[1:]

    if catLetter in rest:
        return []

    rest = perm(rest)

    ret = []
    
    for i in rest:
        [ret.append(j) for j in cat(i, catLetter)]

    return ret 

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

