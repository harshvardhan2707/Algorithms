x=int(input())
y=input()
z=list(map(int,input().split(" ")))
ans=""
m=-1
flag=True
for i in y:
    if(m==-1 and z[int(i)-1]>int(i)):
        m=int(i)-1
        ans+=str(z[int(i)-1])
    elif(int(i)-1==m):
        ans+=str(z[int(i)-1])
    else:
        ans+=i
print(ans)