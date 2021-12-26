def main():
    seq = [2, -8, 3, -2, 4, -10]
    sum = 0
    max_sum = 0
    for i, item in enumerate(seq):
        # take the max sum 
        if sum > max_sum:
            max_sum = sum 
        if sum == 0:
            # dont add negative numbers in front of a sum
            if item > 0:
                sum += item
        else:
            sum += item
        if sum < 0:
            # reset the sum if it reaches below 0
            sum = 0
    print(max_sum)
if __name__ == "__main__":
    main()
