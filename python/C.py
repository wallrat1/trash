s = input()
s = int(s)
sum=0
for i in range(s):
    s2=int(input())
    x = input().split(' ')
    slov={}
    for j in range(s2):
        slov[j+1]=int(x[j])
    spis=[]
    pair=(0,0)
    while slov:
        one=next(iter(slov))
        two=slov[one]
        del slov[one]
        old=10000000000000000000000000000000
        for j in slov:
            if abs(two-slov[j])<old:
                old=abs(two-slov[j])
                pair=(one,j)
        spis.append(pair)
        del slov[pair[1]]

    for j in spis:
        print(j[0],j[1])
    print('')