def find_boards(shorter,longer, k):
    return [i for i in range(shorter*k, longer*k+1, longer-shorter)]

def main():
    shorter = 5
    longer = 6
    k = 20
    print(find_boards(shorter, longer, k))

if __name__ == "__main__":
    main()

