import sys

def main():
    data = sys.stdin.read().strip()
    lines = data.split('\n')
    for line in lines:
        n,k = map(int,line.split())
        butts = n
        while butts >= k != 0:
            cigs = (butts)//k
            butts= cigs+(butts)%k
            n+=cigs
        print(n)
            


if __name__ == "__main__":
    main()
