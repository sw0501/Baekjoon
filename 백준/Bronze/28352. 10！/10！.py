N =int(input())

ans = 1
t = 7*24*60*60
for i in range(1,N+1):
    ans *= i
    
print(int(ans/t))