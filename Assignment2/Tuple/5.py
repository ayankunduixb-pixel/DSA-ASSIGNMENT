# Swap two tuples using tuple assignment

# User input
n1 = int(input("Enter size of first tuple: "))
tup1 = []
print(f"Enter {n1} elements for first tuple:")
for i in range(n1):
    tup1.append(input())
tup1 = tuple(tup1)

n2 = int(input("Enter size of second tuple: "))
tup2 = []
print(f"Enter {n2} elements for second tuple:")
for i in range(n2):
    tup2.append(input())
tup2 = tuple(tup2)

# Swap
tup1, tup2 = tup2, tup1

print("After swapping:")
print("First tuple:", tup1)
print("Second tuple:", tup2)
