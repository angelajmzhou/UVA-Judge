import sys

def main():
    data = sys.stdin.read().strip()
    elements = data.split()
    start=0
    while True:
        n = int(elements[start])
        numbers = list(map(int, elements[start+1:start+n+1]))
        flips=0
        for i in range(len(numbers)-1):
            for j in range(len(numbers)-i-1):
                if numbers[j]>numbers[j+1]:
                    numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
                    flips+=1
        print("Minimum exchange operations : "+str(flips))
        start+=n+1
        if start>len(elements)-1:
            break
    
if __name__ == "__main__":
    main()


        




        