# User-defined input
set1 = set(map(int, input("Enter elements of first set: ").split()))
set2 = set(map(int, input("Enter elements of second set: ").split()))

# Intersection
common = set1 & set2   # or set1.intersection(set2)

print("New set of identical items:", common)
