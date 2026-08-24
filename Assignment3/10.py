# Initialize counters
pos = neg = even = odd = 0

print("Enter 25 numbers:")
numbers = [int(input()) for _ in range(25)]

for num in numbers:
    if num > 0:
        pos += 1
    elif num < 0:
        neg += 1

    if num % 2 == 0:
        even += 1
    else:
        odd += 1

print("Positive numbers:", pos)
print("Negative numbers:", neg)
print("Even numbers:", even)
print("Odd numbers:", odd)
