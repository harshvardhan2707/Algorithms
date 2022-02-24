t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    ans=k
    a=sorted(list(map(int,input().split())),reverse=True)
    for i in a[k:]:
        if(a[k-1]==i):
            ans+=1
        else:
            break
    print(ans)