m = int(input("Enter size of first list: "))
list1 = []
print(f"Enter {m} elements for first list:")
for i in range(m):
    list1.append(input())

n = int(input("Enter size of second list: "))
list2 = []
print(f"Enter {n} elements for second list:")
for i in range(n):
    list2.append(input())

# Manual concatenation
result = []
min_len = m if m < n else n  # handle unequal lengths
for i in range(min_len):
    result.append(list1[i] + list2[i])

print("Concatenated list (index-wise):", result)
