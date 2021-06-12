d = dict()

def coins(n):
    
    if(n == 0):
        return ['']

    tot = 0
    st = []

    if(n >= 25):
        [st.append('q' + i) for i in coins(n - 25)]
    if(n >= 10):
        [st.append('d' + i) for i in coins(n - 10)]
    if(n >= 5):
        [st.append('n' + i) for i in coins(n - 5)]
    if(n >= 1):
        [st.append('p' + i) for i in coins(n - 1)] 

    return st

if __name__ == "__main__":

    c = int(input())
    st = coins(c)

    li = []

    for i in st:
        if(len(i) not in d):
            li.append(i)
            d[len(i)] = 1

    print(li)
