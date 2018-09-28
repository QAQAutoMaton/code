from random import *
import sys
sys.stdout=open("A.in","w")
n=randint(1,100)
print(n)
for i in range(n):
    print(randint(1,1000000000),end=' ')
print()
print(1000)
for i in range(1000):
    print(randint(1,1000),randint(1,n))



