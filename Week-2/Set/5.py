# Remove items from the set at once.
set1 = {10, 20, 30, 40, 50}

for item in [20, 40]:
    if item in set1:
        set1.remove(item)

print(set1)