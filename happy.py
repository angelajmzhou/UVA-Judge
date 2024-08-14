import sys

data = sys.stdin.read().strip().split('\n')
for p in range(1,int(data[0])+1):
    s=int(data[p])
    seen=set()
    while s!=1 and s not in seen:
        seen.add(s)
        total=0
        while s>0:
           total+=(s%10)**2
           s=s//10
        s=total
    if s==1:
        print(f"Case #{p}: {data[p]} is a Happy number.")
    else:
        print(f"Case #{p}: {data[p]} is an Unhappy number.")


