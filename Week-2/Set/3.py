# User-defined input
set1 = set(map(int, input("Enter elements of first set: ").split()))
set2 = set(map(int, input("Enter elements of second set: ").split()))

# Symmetric difference
unique_items = set1 ^ set2   # or set1.symmetric_difference(set2)

print("Unique items from both sets:", unique_items)
