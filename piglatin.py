import sys

vowels = set(("a","e","i","o","u","A","E","I","O","U"))

def main():
    data = sys.stdin.read().splitlines(keepends=True)  # Read input lines with newline characters preserved
    for line in data:
        word = ""
        for ch in line:
            if ch.isalpha():
                word += ch
            else:
                #"piglatinify" the word once it ends
                if word:
                    if word[0] in vowels:
                        print(word + "ay", end="")
                    else:
                        print(word[1:] + word[0] + "ay", end="")
                    word = ""
                print(ch, end="")
        
                
        
    
if __name__ == "__main__":
    main()