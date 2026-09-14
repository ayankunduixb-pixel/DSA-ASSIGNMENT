# Modify tuple by replacing an element

# User input
n = int(input("Enter size of the tuple: "))
tup = []
print(f"Enter {n} elements:")
for i in range(n):
    tup.append(input())

tup = tuple(tup)

# Replace element at index 2 with "X"
new_tup = tup[:2] + ("X",) + tup[3:]

print("Original tuple:", tup)
print("Modified tuple:", new_tup)
