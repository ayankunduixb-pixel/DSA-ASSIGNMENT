n = int(input("Enter size of the array: "))
arr = []

# Input array
print(f"Enter {n} elements: ")
for i in range(n):
    arr.append(int(input()))

unique = []
for x in arr:
    if x not in unique:
        unique.append(x)

print("Array after removing duplicates: ")
print(unique)