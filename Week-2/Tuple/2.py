n = int(input("Enter size of the tuple: "))
tup = []
print(f"Enter {n} elements: ")

for i in range(n):
    tup.append(int(input()))

tup = tuple(tup)

if 20 in tup:
    pos = tup.index(20)
    print(f"Value 20 found at index {pos}")
else:
    print("Value 20 not found in the tuple")