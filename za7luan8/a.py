#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'cnyali_lk'

from decimal import *
from math import *
def check(x,y):
    print(x,y)
    sq5=Decimal.sqrt(Decimal(5))
    a=(1+sq5)/2
    b=(1-sq5)/2
    s=(a**x-b**x)/sq5
    print("Fib({})={}".format(x,s))
    if abs(s-y*y)<=1e-6:
        print("QAQ")


a,b=Decimal(0),Decimal(1)
for i in range(1,501):
    a,b=a+b,a
    sq=Decimal.sqrt(a)
    if(Decimal(floor(sq))==sq):
        check(i,sq)

