N = int(input())

for i in range(N):
    A = int(input())
    a,b = divmod(A,5)
    for j in range(a):
        print('++++ ',end='')
    for j in range(b):
        print('|',end='')
    print()