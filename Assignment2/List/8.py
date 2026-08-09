# Extend nested list manually without built-in functions

# User input
n = int(input("Enter size of the main list: "))
nested_list = []
print(f"Enter {n} elements (can be strings or numbers):")
for i in range(n):
    nested_list.append(input())

m = int(input("Enter size of the sub list: "))
sub_list = []
print(f"Enter {m} elements for sub list:")
for i in range(m):
    sub_list.append(input())

# Manual extension
nested_list += [sub_list]   # same as extend but written manually
print("Updated nested list:", nested_list)
