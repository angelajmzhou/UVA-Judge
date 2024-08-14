import sys
#489
def main():
    while True:
        round = int(sys.stdin.readline().strip())
        if round==-1:
            break
        print("Round "+str(round))
        word = sys.stdin.readline().strip()
        letters = set(word)
        guesses = list(sys.stdin.readline().strip())
        correct = 0
        wrong = 0
        win = len(letters)
        prev_guesses = set()
        for guess in guesses:
            if correct == win:
                break 
            elif wrong >= 7:
                break
            else:
                if guess in letters and guess not in prev_guesses:
                  correct+=1
                  prev_guesses.add(guess)
                elif guess not in letters:
                  wrong+=1
        if correct == win:
                print("You win.")
        elif wrong >= 7:
            print("You lose.")
        else:
            print("You chickened out.")

if __name__ == "__main__":
    main()


        
