n = int(input("Enter size of the list: "))
arr = []
print(f"Enter {n} elements: ")
for i in range(n):
    arr.append(input())

specified = input("Enter the item afte with to insert: ")
new_item = input("Enter the new item to add: ")

if specified in arr:
    pos = arr.index(specified)
    arr.insert(pos+1,new_item)
else:
    print("Specified item not found!")

print("Updated array: ",arr)