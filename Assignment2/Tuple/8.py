# Sort a tuple of tuples by 2nd item using sorted()

# User input
n = int(input("Enter number of inner tuples: "))
main_tup = []
for i in range(n):
    print(f"Enter 2 elements for tuple {i+1}:")
    a = input("First element: ")
    b = input("Second element: ")
    main_tup.append((a, b))

main_tup = tuple(main_tup)

# Sort by 2nd item
sorted_tup = tuple(sorted(main_tup, key=lambda x: x[1]))

print("Original tuple of tuples:", main_tup)
print("Sorted tuple of tuples (by 2nd item):", sorted_tup)
