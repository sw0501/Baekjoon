N = int(input())

Fibo = [0 for i in range(N+1)]
Fibo[0] = 0
if N!=0:
    Fibo[1] = 1

i=2
while i <= N:
   Fibo[i]= Fibo[i-1]+Fibo[i-2]
   i = i+1

print(Fibo[N])