import sys

data = sys.stdin.read().strip().split('\n')
for line in data:
    a,b = line.split()
    print(int(a)^int(b))