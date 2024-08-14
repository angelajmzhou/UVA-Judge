import sys
import re

input = sys.stdin.read().strip().split('\n')
linenum = 0
counter = 1

while linenum<len(input):
    k, e = map(int,(input[linenum]).split())
    keywords = set()
    linenum+=1
    max=0
    sentences=[]

    for a in range(linenum, linenum+k):
        keywords.add(input[a])
    linenum+=k
    for b in range(linenum, linenum+e): 
        hitcount = 0
        excuse = re.split(r'\W+', input[b])
        for word in excuse:
            if word.lower() in keywords:
                hitcount+=1
        if hitcount > max:
            max = hitcount
            sentences = [input[b]]
        elif hitcount == max:
            sentences.append(input[b])
    linenum+=e
    print("Excuse Set #"+str(counter))
    for sentence in sentences:
        print(sentence)
    print()
    counter+=1

        



    