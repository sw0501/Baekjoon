import sys

for i in range(3):
    num = int(sys.stdin.readline())
    answer = 0
    for j in range(num):
        temp = int(sys.stdin.readline())
        answer = answer + temp
    if answer==0:
        print("0")
    elif answer>0:
        print("+")
    else:
        print("-")