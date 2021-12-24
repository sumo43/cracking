
def stringToBool(s: str) -> bool:
    return s == '1'


def count_ways(exp:str, result:bool) -> int:

    if len(exp) == 0:
        return 0

    if len(exp) == 1:
        return 1 if stringToBool(exp) == result else 0
    
    ways = 0
    for i in range(1, len(exp), 2):
        left = exp[:i]
        right = exp[i + 1:]

        left_true = count_ways(left, True)
        left_false = count_ways(left, False)
        right_true = count_ways(right, True)
        right_false = count_ways(right, False)

        total = (left_true + left_false) * (right_true + right_false)

        total_true = 0

        if exp[i] == "|":
            total_true = (
                    left_true * right_true
                    + left_false * right_true
                    + left_true * right_false
            )
        elif exp[i] == "&":
            total_true = (
                    left_true * right_true
            )
        elif exp[i] == "^":
            total_true = (
                    left_true * right_false 
                    + left_false * right_true
            )


        subways = total_true if result else (total - total_true)
        ways += subways

    return ways


def evaluate(exp: str, result: bool) -> int:
    return count_ways(exp, result)


if __name__ == "__main__":

    print(evaluate("1^0|0|1", False))



    
    
