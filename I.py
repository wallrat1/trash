x,y=[int(i) for i in input().split(' ')]
proces={}
k=[int(j)for j in input().split(' ')]
k.sort()
rez=0
for i in k:
    proces[i]=0
for i in range(y):
    start,long=[int(j)for j in input().split(' ')]
    flag=0
    for j in proces:
        if proces[j] < start:
            proces[j]=0
            if not flag:
                proces[j]=long+start-1
                rez+=j*(long)
                flag=1
print(rez)



