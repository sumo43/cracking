

def sub(s, n):
    
    # get all substrings of the string
    if(len(s) == 1):
        return s 
    
    return [i for i in s if i != n] 


            
def cat(s, n):

    li = []
    li.append(s + n)
    for i in range(len(s)):
        tl = s[:i]
        tl += n
        tl += s[i:]

        li.append(tl)
    

    return li
    

def perm(s):

    if(len(s) == 1):
        return [s]
    #take enach of the permutations of the previous number

    catLetter = s[0]
    rest = s[1:]

    rest = perm(rest)

    ret = []
    
    for i in rest:
        [ret.append(j) for j in cat(i, catLetter)]

    return ret 



if __name__ == "__main__":

    s = 'abcd'
    s = perm(s) 
    print(s)

