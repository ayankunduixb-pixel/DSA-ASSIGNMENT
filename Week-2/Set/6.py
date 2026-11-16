# Return a set of elements present in Set A or B, but not both.

set1 = {1,2,3,4}
set2 = {2,3,5,6}
print("Updated set1: ",set1 ^ set2)

# Method-2

set1 = set(map(int, input("Enter elements of set1: ").split()))
set2 = set(map(int, input("Enter elements of set2: ").split()))

result = set()

for x in setA:
    if x not in setB:
        result.add(x)

for x in setB:
    if x not in setA:
        result.add(x)

print(result)