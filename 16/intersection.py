

def compute_intersection(a, b):

    x0a, y0a = a[0]
    x1a, y1a = a[1]

    x0b, y0b = b[0]
    x1b, y1b = b[1]
    
    d1 = (x0a - x0b) + (y0a - y0b)
    d2 = (x1a - x1b) + (y1a - y1b)

    if (d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0):
        return True
    else:
        return False

if __name__ == "__main__":
    
    line1 = ((0, 0), (10,10))
    line2 = ((3, 6), (3, 11))

    inter = compute_intersection(line1, line2)
    
    print(inter)
