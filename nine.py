#problem 10922
import sys
def main():
    data = sys.stdin.read().strip()
    lines = data.split('\n')
    for line in lines:
        number = int(line.strip())
        if number == 0:
                break
        print(number, end=" ")
        res = ninetest(number)
        if res == 0:
              print("is not a multiple of 9.")
        elif res == 1:
              print("is a multiple of 9 and has 9-degree 1.")
        else:
              print("is a multiple of 9 and has 9-degree "+str(res)+".")

        
def ninetest(num):
    n=num
    sum=0
    while(n>0):
             sum+=n%10
             n//=10
    if sum==9:
            return 1
    elif sum>0 and sum % 9 == 0:
            return 1+ninetest(sum)
    return 0

if __name__ == "__main__":
    main()