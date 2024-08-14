import sys
import math

def main():
    input = sys.stdin.read().strip().split('\n')
    for garden in input:
        a, b, c = map(int, garden.split())
        #heron's formula
        s = (a + b + c) / 2
        A = math.sqrt(s * (s - a) * (s - b) * (s - c)) 
        r = A / s  #radius of roses
        R = (a * b * c) / (4 * A)  # Radius of violets
        
        area_incircle = math.pi * (r ** 2) 
        area_circumcircle = math.pi * (R ** 2) 
        
        area_sunflowers = area_circumcircle - A  
        area_violets = A - area_incircle  
        
        print(f"{area_sunflowers:.4f} {area_violets:.4f} {area_incircle:.4f}")

if __name__ == "__main__":
    main()
