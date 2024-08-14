import sys
import math

def main():
    data = sys.stdin.read().strip()
    lines = data.split('\n')
    for line in lines:
        sum=0
        line = line.strip()
        for char in line:
            if char.isupper():
                #print("char: "+ char + "val: " + str(ord(char)-38), end = " ")
                sum += ord(char)-38
            else:
                #print("char: "+ char + " val: " + str(ord(char)-97), end=" ")
                sum+= ord(char)-96
        if isprime(sum):
            print("It is a prime word.")
        else:
            print("It is not a prime word.")
            
def isprime(num):
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(num) + 1), 2):
        if num % i == 0:
            return False
    return True

if __name__ == "__main__":
    main()
