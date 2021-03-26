import math

def factors(n):
   fac = []
   x = 2
   while(x<=math.sqrt(n)):
      while(n%x==0):
         fac.append(x)
         n //=x
      x+=1
   if(n>1):
      fac.append(n)
   return fac

if __name__=="__main__":
   n = 8912234
   for x in factors(n):
      print(x,end=" ") # 2 47 94811
   print(end="\n")
