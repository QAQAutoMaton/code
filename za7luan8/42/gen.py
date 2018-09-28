import os
import random
import io

for id in range(1,4):
    if id<=3:
        n=10
        N=100000
    else:
        n=150000
        N=2000000000
    with open("wcd{}.in".format(id),"w") as f:
        f.write("{}\n".format(n))
        w=random.randint(2,N)
        for i in range(n):
            if i%2==1:
                f.write("{} {}\n".format(random.randint(1,N//w)*w,random.randint(1,N)))
            else:
                f.write("{} {}\n".format(random.randint(1,N),random.randint(1,N//w)*w))

    os.system("./std<wcd{0}.in>wcd{0}.ans".format(id))
