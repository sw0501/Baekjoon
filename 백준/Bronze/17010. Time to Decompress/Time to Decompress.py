n = int(input())

for i in range(n):
    a,b = input().split()
    a = int(a)
    for j in range(a):
        print(b,end='')
    print("")