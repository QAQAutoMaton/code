import random
import io
import os
for i in range(1,11):
    if i<=3:
        n=300
    elif i<=6:
        n=5000
    else:
        n=100000
    with open("bit{}.in".format(i),"w") as f:
        f.write("{}\n".format(n))
        s=""
        for tt in range(n):
            s+="{}".format(random.randint(0,1))
        f.write(s+"\n")
        s=""
        for tt in range(n):
            s+="{}".format(random.randint(0,1))
        f.write(s+"\n")
    os.system("./std<bit{0}.in>bit{0}.ans".format(i))
    print(i,"OK")
