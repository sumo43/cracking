
# value of a paren. ( is +, ) is -, a string cannot be negative, and can only be positive if num_pos <= n
def value(s, n):
    if(len(s) == 0):
        return -1
    n = 0
    for i in range(len(s)):
        if(s[i] == '('):
            n += 1
        elif s[i] == ')':
            n -= 1
    return n

def parens(n, l):

    if(n == 1):
        return [('(',  1)]


    prev_li = parens(n - 1, l)

    li = []

    for paren, prev_v in prev_li:
        
        for brace in [')', '(']:
            new_v = prev_v

            brace_paren = paren + brace

            if brace == ')':
                new_v -= 1
            elif brace == '(':
                new_v += 1

            if(new_v > -1 and new_v <= l - n):
                
                li.append((brace_paren, new_v))


    return li

if __name__ == "__main__":
    
    s = parens(6, 6)
    print([i[0] for i in s])




