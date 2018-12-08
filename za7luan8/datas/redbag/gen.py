#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'cnyali_lk'
import random,os,io
p=10**9+7
for i in range(1,11):
    with io.open("redbag{}.in".format(i),"w") as f:
        if i<=3:
            k=n=1
            w=random.randint(1,p-1)
        elif i<=6:
            k=random.randint(2,10)
            n=random.randint(k,int(10**18))
            w=random.randint(1,(p-1)//2**k)*2**k
        else:
            w=random.randint(1,p-1)
            k=random.randint(2,10**18)
            n=random.randint(k,int(10**18))
        f.write("{} {} {}".format(w,n,k))        
    os.system("./std<redbag{0}.in>redbag{0}.ans".format(i,i))
