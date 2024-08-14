import sys
#913
data = sys.stdin.read().strip().split('\n')

for line in data:
    n = int(line.strip())
    linenum = 1+((n-1)//2)
    numcount = (linenum)**2 #sum of n odd numbers --"number of numbers up to and incl line"
    print(numcount**2-(numcount-3)**2)
    