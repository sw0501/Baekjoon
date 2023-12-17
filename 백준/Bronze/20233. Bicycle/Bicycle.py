a = int(input())
x = int(input())
b = int(input())
y = int(input())
T = int(input())

A = a + 21 * x * (T-30 if T-30 > 0 else 0)
B = b + 21 * y * (T-45 if T-45 > 0 else 0)

print(A,end=' ')
print(B)