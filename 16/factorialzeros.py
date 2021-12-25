
def get_factorial_zeros(num):
    # get the number of trailing zeros of this number, factorial
    five_num = 0
    mult = 5
    
    while mult <= num:
        add = (num) // mult
        if add == 0:
            break
        else:
            five_num += add
        mult *= 5
    
    return five_num

if __name__ == "__main__":
    num = 4617
    print(get_factorial_zeros(num))
