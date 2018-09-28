#! /usr/bin/python3
"""
Author: CNYALI_LK
LANG: python3
PROG: d.py
Mail: cnyalilk@vip.qq.com
"""
import os
import math
import random
import io
case=0
while True:
    s=input()
    case=case+1
    if not s:
        break
    print('Case {}:'.format(case),end=' ')
    a=s.split(' ')

    if float(a[0])<float(a[1]):
        print('Smaller')
    elif float(a[0])>float(a[1]):
        print('Bigger')
    else:
        print('Same')
