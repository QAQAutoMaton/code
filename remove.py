import os
import io
import sys
os.system("rm -rf trash 2>/dev/null")
trash_file=os.path.realpath('trash')
def make(s):
    d=os.listdir('.')
    os.system("mkdir '"+trash_file+s+"'") 
    for i in d:
        if i!=".git":
            if(os.path.isdir(i)):
                os.chdir(i)
                make(s+'/'+i)
                os.chdir('..')
            else:
                txt=os.path.splitext(i)[-1]
                if(txt == ""):
                    os.system('mv {} "{}/{}"'.format(i,trash_file,s+'/'+i))
                    print(s+'/'+i, "Removed")
make('')
print('DONE')
while True :
    s=input("ok?(Y/n):")
    if s=='Y':
        os.system("rm -rf trash")
        sys.exit()
    elif s=='n':
        sys.exit()
    else:
        os.system("(Y/n)!!!!")

 
