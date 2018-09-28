import os
import random
import io

for sub in range(4):
    for dt in range(1,6):
        id=sub*5+dt
        with open("flower{}.in".format(id),"w") as f:
            if(sub==0):
                t=0
            elif sub==1:
                t=10
                n=10000
            elif sub==2:
                t=100000
                n=1000000
            else:
                t=100000
                n=10**15
            f.write("{} {}\n".format(t,dt))
            for i in range(t):
                f.write("{} {}\n".format(random.randint(1,n),random.randint(1,n)))
        os.system("./std<flower{0}.in>flower{0}.ans".format(id))
