# Read list of elements
elements = list(map(int, input("Enter elements of list: ").split()))

# Create an empty set
my_set = set()

# Add list elements to set
my_set.update(elements)

print("Set after adding elements:", my_set)
