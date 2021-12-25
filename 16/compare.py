def compare(a, b):
    k = a - b
    k = max(0, k)
    k = min(k, 1)

    return a * k + b * (not k)
if __name__ == "__main__":
    a = 122
    b = 7
    print(compare(a, b))
