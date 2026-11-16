# Update set1 by adding items from set 2, except common items.
set1 = {1,2,3,4}
set2 = {2,3,5,6}
print("Updated set1: ",set1 | set2)

# Method-2

set1 = set(map(int, input("Enter set1 elements: ").split()))
set2 = set(map(int, input("Enter set2 elements: ").split()))

for x in set2:
    if x not in set1:
        set1.add(x)

print("Updated set1:", set1)

