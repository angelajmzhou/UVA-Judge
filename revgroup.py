import sys

def main():
    while True:
        line = sys.stdin.readline().strip()
        if line == '0':
            break
        g, sentence = line.split()
        g=int(g)
        interval = len(sentence)//g
        revstring = ""
        for i in range(interval, len(sentence)+1, interval):
            seg = sentence[i-interval:i]
            revstring+=seg[::-1]
        print(revstring)


if __name__ == "__main__":
    main()

