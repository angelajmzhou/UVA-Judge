import sys
import math

def main():
    lines = sys.stdin.read().strip().split('\n')
    for i in range(0,len(lines),2):
        if i+1<len(lines):
            coefficients=list(map(int, lines[i].split()))
            xvals=list(map(int, lines[i+1].split()))
            order = len(coefficients)-1
            outputs=[]
        else:
            print("Odd Number Lines")
            return
        for x in xvals:
            res=0
            for k in range(order+1):
                res+=coefficients[order-k]*(x**k)
            outputs.append(res)
        print(' '.join(map(str,outputs)))
            
    

if __name__ == "__main__":
    main()