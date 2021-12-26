import random
from datetime import datetime

def rand5():
    return random.randint(0, 5)
def rand25():
    return 5 * rand5() + rand5()
def rand7():
    r = rand25() // 3
    while r > 6:
        r = rand25() // 3
    return r
if __name__ == "__main__":
    d = dict()
    for i in range(1000000):
        r = rand7()
        if r not in d:
            d[r] = 1
        else:
            d[r] += 1
    print(d)
    for i in range(7):
        print(f'{i}: {d[i] / 1000000}')


    
