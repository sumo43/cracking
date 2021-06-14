


width = lambda x: x[0]
height = lambda x: x[1]
depth = lambda x: x[2]

def stackable(currentStack, box):
    if len(currentStack) == 0:
        return True

    top = currentStack[-1]
    if(width(box) < width(top) and height(box) < height(top)):
        return True
    return False

def solveStack(boxes, currentStack = [], currentDepth = 0):
    
    heights = []


    for box in boxes:
        if box not in currentStack and stackable(currentStack, box):
            heights.append(solveStack(boxes, currentStack + [box], currentDepth + depth(box)))


    if len(heights) == 0:
        return currentDepth

        
    if(len(heights) == 0):
        return currentDepth

    return max(heights)




if __name__ == "__main__":

    boxes = [
            #w, h, d
            [2, 2, 3],
            [3, 4, 4],
            [5, 2, 1],
            [7, 6, 2],
            [5, 5, 5],
            [1, 1, 1],
            ]
    print(solveStack(boxes))
