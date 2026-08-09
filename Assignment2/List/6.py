n = int(input("Enter size of the list: "))
arr = []
print(f"Enter {n} strings: ")
for i in range(n):
    arr.append(input())

result = []
for i in range(n):
    if arr[i] != "":
        result.append(arr[i])

print("List after removing empty strings:",result)