# Count occurrences manually without built-in functions

# User input
n = int(input("Enter size of the tuple: "))
tup = []
print(f"Enter {n} elements:")
for i in range(n):
    tup.append(input())

tup = tuple(tup)

x = input("Enter the item to count: ")

# Manual counting
count = 0
for i in range(n):
    if tup[i] == x:
        count += 1

print(f"Item '{x}' occurs {count} times in the tuple.")
