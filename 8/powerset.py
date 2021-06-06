







def powerset(set):
    if(len(set) == 0):
        return [[]]
    else:

        sets = [[]]

        for i in range(len(set)):

            sets.append(set[not i])

