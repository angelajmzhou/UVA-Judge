import sys

#10071

data = sys.stdin.read().strip().split('\n')

for particle in data:
    v,t = map(int, particle.split())
    print(v*t*2)