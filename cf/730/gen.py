#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'cnyali_lk'
import sys,random
sys.stdout=open("j.in","w")
n=100
print(n)
a=[]
b=[]
for i in range(n):
    l=random.randint(1,100)
    r=random.randint(1,100)

    if l>r:
        l,r=r,l
    a.append(l)
    b.append(r)
for i in a:
    print(i,end=' ')
print()
for i in b:
    print(i,end=' ')
print()
