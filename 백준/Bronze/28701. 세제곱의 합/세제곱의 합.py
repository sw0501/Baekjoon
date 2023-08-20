N = int(input())

sum = 0
dou = 0
tri = 0

for i in range(1,N+1):
    sum = sum + i
    tri = tri + i*i*i

dou = sum*sum

print(sum)
print(dou)
print(tri)