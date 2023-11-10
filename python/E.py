s=int(input())
for _ in range(s):
    input()
    x=input().split(' ')
    old=x[0]
    kash=set()
    flag=0
    for i in x:
        if old==i:
            pass
        elif i in kash:
            print("NO")
            flag=1
            break
        elif old!=i:
            kash.add(old)
            old=i
    if not flag:
        print("YES")






