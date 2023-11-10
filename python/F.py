s=int(input())
answer=[]
s1=0
for z in range(s):
    s1=int(input())
    spis=[]
    flag=0
    kash=[]
    for _ in range(s1):
        n = input().split("-")
        n = [j.split(":") for j in n]
        kash.append(n)
    for n in kash:
        if int(n[0][0])<24 and int(n[0][0])>=0 and int(n[0][1])<60 and int(n[0][1])>=0 and int(n[0][2])<60 and int(n[0][2])>=0 and int(n[1][0])<24 and int(n[1][0])>=0 and int(n[1][1])<60 and int(n[1][1])>=0 and int(n[1][2])<60 and int(n[1][2])>=0:
           min1 = int(n[0][0])*60*60 + int(n[0][1])*60 + int(n[0][2])
           min2 = int(n[1][0])*60*60 + int(n[1][1])*60 + int(n[1][2])
           if min1<=min2:
               spis.append((min1,min2))
           else:
               answer.append("NO")
               flag=1
               break
        else:
            answer.append("NO")
            flag=1
            break
    if flag:
        continue
    spis.sort()
    for i in range(len(spis)-1):
        if not (spis[i][1]<spis[i+1][0]):
            answer.append("NO")
            flag=1
            break
    if flag:
        continue
    else:
        answer.append("YES")
for i in answer:
    print(i)

