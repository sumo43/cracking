def anagram(a, b):
    h = dict()
    for item in a:
        if item not in h:
            h[item] = 1
        else:
            h[item] += 1

    for word in b:
        if word in h:
            if h[word] == 0:
                return False
            else:
                h[word] -= 1
        else:
            return False
    

    for key in h.keys():
        if h[key] != 0:
            return False

    return True


def anagramSort(li):
    
    anagrams = []
    for item in li:
        a = 0 
        for i in range(len(anagrams)):
            if anagram(item, anagrams[i][0]):
                anagrams[i].append(item)
                a += 1
        if a == 0:
            anagrams.append([item])
    
    ret = []
    [[ret.append(item) for item in anagramList] for anagramList in anagrams] 
    return ret



if __name__ == "__main__":

    li = [

        "aag",
        "tomato",
        "ree",
        "eer",
        "aga",
        "matoto"

    ]
    
    print(anagramSort(li))
        
    
