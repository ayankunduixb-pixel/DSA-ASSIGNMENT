n = int(input("Enter size of the list: "))
arr = []

# Input th array
print(f"Enter {n} elements:")
for i in range(n):
    arr.append(int(input()))

# Insert position and value
pos = int(input("Enter position (0-based index): "))
val = int(input("Enter value to insert: "))

# Insert element
arr.insert(pos,val)

# Updated array
print("Updated array: ")
print(arr)