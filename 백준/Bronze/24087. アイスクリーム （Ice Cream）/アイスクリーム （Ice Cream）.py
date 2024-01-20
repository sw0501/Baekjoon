S = int(input())
A = int(input())
B = int(input())

S -= A
price = 250

if S > 0:
    C,D = divmod(S,B)
    if D!=0:
        C+=1
    price += C *100
    
print(price)
