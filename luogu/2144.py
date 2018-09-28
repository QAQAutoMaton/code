#! /usr/bin/python3
"""
Author: CNYALI_LK
LANG: python3
PROG: 2144.py
Mail: cnyalilk@vip.qq.com
"""
import os,math,random,io
n=int(input())
f=1
s=1
ans=0
for i in range(n):
    ans+=f*(n-i)*(n-i)
    f=f+s
    s=s+f
print(f+n)
