# Replace list item using index()

# User input
n = int(input("Enter size of the list: "))
arr = []
print(f"Enter {n} elements:")
for i in range(n):
    arr.append(input())

old_item = input("Enter the item to replace: ")
new_item = input("Enter the new value: ")

# Replace if found
if old_item in arr:
    pos = arr.index(old_item)
    arr[pos] = new_item
else:
    print("Item not found!")

print("Updated list:", arr)
