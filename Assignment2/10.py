n = int(input("Enter size of the list: "))
arr = []
print(f"Enter {n} elements:")
for i in range(n):
    arr.append(input())

item = input("Enter the item to remove: ")

while item in arr:
    arr.remove(item)

print("List after removing all occurences: ",arr)