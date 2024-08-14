import sys
import statistics

#11875

t = int(sys.stdin.readline().strip())

for case in range(t):
    numbers = sys.stdin.readline().strip().split()
    n = numbers[0]
    numbers.pop(0)
    print("Case "+str(case+1)+": " + statistics.median(numbers))
    