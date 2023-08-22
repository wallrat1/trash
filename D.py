s=int(input())
for _ in range(s):
    input()
    x,y=input().split(' ')
    mat=[]
    for _ in range(int(x)):
        mat.append([int(j) for j in input().split(' ')])
    s1=int(input())
    old=-1
    s2=input().split(' ')
    for l in s2:
        k=int(l)-1
        if k!=old:
            mat.sort(key=lambda q : q[k])
            old=k
    for i in range(int(x)):
        for j in range(int(y)):
            if j!=0:
                print(' ',end="")
            print(mat[i][j],end="")
        print('')
    print('')