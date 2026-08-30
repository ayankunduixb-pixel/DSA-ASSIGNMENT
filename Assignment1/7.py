n = int(input("Enter size of the array: "))
arr = []
print(f"Enter {n} elements: ")
for i in range(n):
    arr.append(int(input()))

maxi = arr[0]
mini = arr[0]

for x in arr:
    if x > maxi:
        maxi = x
    if x < mini:
        mini = x

print("Maximum value in array: ",maxi)
print("Minimum value in array: ",mini)