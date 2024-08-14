import sys
#problem 11942

def main():
    print("Lumberjacks:")
    n = int(sys.stdin.readline().strip())
    for i in range(n):
        elements = sys.stdin.readline().strip().split()
        lengths = list(map(int, elements))
        if(lengths == sorted(lengths) or lengths == sorted(lengths, reverse=True)):
            print("Ordered")
        else:
            print("Unordered")


if __name__ == "__main__":
    main()


        




        