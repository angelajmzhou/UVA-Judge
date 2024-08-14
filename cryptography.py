import sys
import math

def main():
    input = sys.stdin.read
    data = input().split()

    i=0
    while i<len(data):
        n = int(data[i])
        p = int(data[i+1])
        #implement function here
        k= int(round(p ** (1/n)))
        print(k)
        i+=2

if __name__ == "__main__":
    main()