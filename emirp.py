import sys
import math

def main():
    data = sys.stdin.read().strip()
    lines = data.split('\n')
    for line in lines:
        line = line.strip()
        if not line: 
            continue
        number = int(line)
        print(number, end=" ")
        if not primetest(number):
            print("is not prime.")
        else:
            rev = reverse_number(number)
            if number != rev and primetest(rev): 
                print("is emirp.")
            else:
                print("is prime.")

def primetest(num):
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(num) + 1), 2):
        if num % i == 0:
            return False
    return True

def reverse_number(num):
    rev = 0
    while num > 0:
        rev = rev * 10 + num % 10
        num //= 10
    return rev

if __name__ == "__main__":
    main()
