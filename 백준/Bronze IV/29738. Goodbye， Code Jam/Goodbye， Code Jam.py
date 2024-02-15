T = int(input())

for i in range(1,T+1):
    num = int(input())
    if num <= 25:
        print("Case #" + str(i) + ": World Finals")
    elif num <= 1000:
        print("Case #" + str(i) + ": Round 3")
    elif num <= 4500:
        print("Case #" + str(i) + ": Round 2")
    else:
        print("Case #" + str(i) + ": Round 1")