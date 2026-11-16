# Remove all occurrences of a specific item from a list.
l = list(map(int,input("Enter list elements: ").split()))
item = int(input("Enter the item to delete:"))

for x in l:
    if x != item:
        print(x,end=" ")
