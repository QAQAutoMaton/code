a,b,ans=1,1,0
while a<=4000000:
    a,b=a+b,a
    if a%2==0:
        ans+=a
print(ans)
