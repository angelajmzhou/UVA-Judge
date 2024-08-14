import sys

def main():
    n = int(sys.stdin.readline().strip())
    sites = dict()
    for i in range(n):
        print("Case #"+str(i+1)+":")
        for j in range(10):
            site, priority = sys.stdin.readline().split()
            priority = int(priority)
            if(priority in sites):
                sites[priority].append(site)
            else:
                sites[priority] = [site] #creates new list
        recommend = max(sites.keys())
        for site in sites[recommend]:
            print(site)
        sites.clear()


            
if __name__ == "__main__":
    main()
