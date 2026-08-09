n = int(input("Enter size of the list: "))
arr = []
print(f"Enter {n} elements:")
for i in range(n):
    arr.append(int(input()))

squared = []
for i in range(n):
    squared.append(arr[i]* arr[i])

print("Squared list: ",squared)