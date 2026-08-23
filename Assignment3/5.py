# Read array
arr = list(map(int, input("Enter elements of array: ").split()))

# Read position and value
pos = int(input("Enter position to insert (0-based index): "))
val = int(input("Enter value to insert: "))

# Insert element
arr.insert(pos, val)

print("Updated array:", arr)
