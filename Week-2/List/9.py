# 9.Replace list’s item with new value if found

l = list(map(int,input("Enter list items: ").split()))
item = int(input("Enter the element to replace: "))
new_value = int(input("Enter the new value: "))

for i in range(len(l)):
    if l[i] == item:
        l[i] = new_value

print("Updated list:", l)