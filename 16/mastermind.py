def mastermind(solution, guess):
    hits = []
    pseudo_hits = set()
    for i in range(len(solution)):
        if guess[i] == solution[i]:
            hits.append(guess[i])

    for letter in guess:
        if letter in solution and letter not in hits:
            pseudo_hits.add(letter)

    print(f'{len(hits)} hits and {len(pseudo_hits)} pseudo hits')
if __name__ == "__main__":
    mastermind('rgby', 'ggrr')


