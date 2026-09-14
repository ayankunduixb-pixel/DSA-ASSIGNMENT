n = int(input("Enter number of terms: "))
a=0
b=1
for i in range(1,n+1):
    print(a,end=" ")
    a,b = b,a+b
