A,B = map(int,input().split(' '))

cnt = 0

if A >= B:
    cnt = B
else:
    cnt = A+1

print(cnt)