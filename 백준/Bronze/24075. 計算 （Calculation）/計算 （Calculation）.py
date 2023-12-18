A,B = map(int,input().split())

M = A+B if A+B >A-B else A-B
m = A-B if A+B >A-B else A+B

print(M)
print(m)