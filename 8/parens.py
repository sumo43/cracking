
def checkValid(s):
    if(len(s) == 0):
        return -1
    n = 0
    for i in range(len(s)):
        if(s[i] == '('):
            n += 1
        elif s[i] == ')':
            n -= 1
    return n

def parens(n):

    if(n == 1):
        return ['(']

    p = parens(n - 1)

    li = []

    for paren in p:
        for b in [')', '(']:
            bp = paren + b
            if(checkValid(bp) >= 0):
                li.append(bp)

    return li


if __name__ == "__main__":
    
    s = parens(8)
    s = [i for i in s if checkValid(i) == 0]
    print(s)




