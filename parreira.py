import sys
#11805
data = sys.stdin.read().split('\n')
n = int(data[0])
for i in range(1,n+1,1):
    n,k,p = map(int,data[i].strip().split())
    players = list(range(1,int(n)+1,1))
    last = players[(k+p-1)%n]
    print("Case "+str(i)+": " + str(last))

    
