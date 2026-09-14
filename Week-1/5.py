n = int(input("Enter size of the array: "))
arr = []
print(f"Enter {n} elements: ")
for i in range(n):
    arr.append(int(input()))
choice = int(input("Delete by:\n 1.index \n 2.value \n Enter choice: "))

if choice == 1:
    pos = int(input("Enter index: "))
    if(0 <= pos <=len(arr)):
        arr.pop(pos)
    else:
        print("Invalid index")

if choice == 2:
    val = int(input("Enter value: "))
    if val in arr:
        arr.remove(val)
    else:
        print("Value not found")

# Print the updated array
print("Updated array: ")
print(arr)