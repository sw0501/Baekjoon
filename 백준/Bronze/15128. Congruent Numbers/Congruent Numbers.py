import math

p1,q1,p2,q2 = map(int,input().split())

p = p1 * p2
q = q1 * q2 * 2

if p % q == 0:
    print(1)
else :
    print(0)