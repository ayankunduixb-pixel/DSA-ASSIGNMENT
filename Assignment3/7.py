s = input("Enter a string: ")

# Method 1: Using slicing
print("Reversed string :", s[::-1])

# Method 2: Manual loop
rev = ""
for ch in s:
    rev = ch + rev
print("Reversed string :", rev)
