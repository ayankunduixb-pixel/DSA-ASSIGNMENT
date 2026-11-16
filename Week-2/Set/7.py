# Check if two sets have any elements in common. If yes, display the
# common elements.

set1 = {1,2,3,4}
set2 = {2,3,5,6}
print("Updated set1: ",set1 & set2)

# Method-2
set1 = set(map(int, input("Enter elements of set1: ").split()))
set2 = set(map(int, input("Enter elements of set2: ").split()))

common = set()

for x in set1:
    if x in set2:
        common.add(x)

set1 = common

print("Updated set1:", set1)