def mult(a, b):
    sum = 0
    for i in range(b):
        sum += a
    return sum
def divide(a, b):
    sum = 0
    i = 0
    while sum != a:
        sum += b
        i += 1
    return i
def subtract(a, b):
    i=0
    if a>0:
        while i+b != a:
            i += 1
        return i
if __name__=="__main__":
    print(mult(5,6))
    print(divide(30,6))
    print(subtract(50,6))

