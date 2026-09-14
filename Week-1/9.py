n = int(input("Enter size of the array: "))
arr = []
print(f"Enter {n} elements: ")
for i in range(n):
    arr.append(int(input()))

freq = {}
for x in arr:
    freq[x] = freq.get(x,0) + 1

print("Frequency of elements: ")
for key,value in freq.items():
    print(f"{key} occurs {value} times")