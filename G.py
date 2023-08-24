x,y=[int(j) for j in input().split(' ')]
main=[]
for _ in range(y):
    main.append(input().split(' '))
slov={}
kash_slov={}
rez=[]
for i in range(x):
    slov[i+1]=set()
    kash_slov[i+1]=0
for i in range(x):
    for j in main:
        if int(j[0])==i+1:
            slov[i+1].add(int(j[1]))
        elif int(j[1])==i+1:
            slov[i+1].add(int(j[0]))
for i in range(x):
    flag=0
    kash_list=[]
    old = -1
    for j in slov[i+1]:
        for g in slov[j]:
            if g!=i+1 and not(g in slov[i+1]):
                kash_slov[g]+=1
                flag=1
    if not flag:
        print(0)
        continue
    for l in kash_slov:
        if kash_slov[l]>old:
            kash_list.clear()
            kash_list.append(l)
            old=kash_slov[l]
        elif kash_slov[l]==old:
            kash_list.append(l)
        kash_slov[l]=0
    kash_list=sorted(kash_list)
    print(" ".join(map(str, kash_list)))








