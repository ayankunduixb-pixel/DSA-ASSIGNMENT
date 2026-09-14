# Reverse a tuple
n = int(input("Enter size of the tupple: "))
tup = []
print(f"Enter {n} elements: ")
for i in range(n):
    tup.append(input())

tup = tuple(tup)

rev_tup = tup[::-1]
print("Reversed tuple:",rev_tup)