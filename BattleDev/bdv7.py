# Bissextile year

def isBix(x):
    return "BISSEXTILE" if((x%4==0 and x%100!=0) or x%400==0) else "NO"

if __name__=='__main__':
    x1 = 2012
    x2 = 2015
    print(isBix(x1),end="\n")
    print(isBix(x2),end="\n")