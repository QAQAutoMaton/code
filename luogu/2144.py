#! /usr/bin/python3
"""
Author: CNYALI_LK
LANG: python3
PROG: 2144.py
Mail: cnyalilk@vip.qq.com
"""
import os,math,random,io
n=int(input())
f=[1]
g=[0]
for i in range(1,n+1):
    sf=0
    sg=0
    for j in range(i):
        sf+=f[j]*(i-j)
        sg+=f[j]*(i-j)*(i-j)
    f.append(sf)
    g.append(sg)

print(g[n])
