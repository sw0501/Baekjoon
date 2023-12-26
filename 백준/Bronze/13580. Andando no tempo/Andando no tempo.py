A,B,C = map(int,input().split())

mylist = []
mylist.append(A)
mylist.append(B)
mylist.append(C)
mylist.sort()

if mylist[0]==mylist[1] or mylist[1]==mylist[2] or mylist[0]+mylist[1]==mylist[2]:
    print("S")
else:
    print("N")