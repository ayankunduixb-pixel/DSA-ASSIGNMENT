n = int(input("Enter size of the list: "))
arr = []
print(f"Enter {n} elements: ")
for i in range(n):
    arr.append(int(input()))

print("Reversed list (using slicing):", arr[::-1])