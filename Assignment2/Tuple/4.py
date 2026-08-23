n = 4
tup = []
print(f"Enter {n} elements: ")
for i in range(n):
    tup.append(input())

tup = tuple(tup)

a,b,c,d = tup
print("Unpacked values: ")
print("a=",a)
print("b=",b)
print("c=",c)
print("d=",d)
