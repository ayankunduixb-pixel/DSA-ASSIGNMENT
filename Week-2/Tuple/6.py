# Copy specific elements from one tuple to a new tuple.
n = int(input("Enter size of the tuple: "))
tup = []
print(f"Enter {n} elements: ")
for i in range(n):
    tup.append(input())

tup = tuple(tup)

indices = [1, 3, 4]

new_tup = tuple(tup[i] for i in indices if i < len(tup))
print("Original tuple:", tup)
print("New tuple with specific elements:", new_tup)