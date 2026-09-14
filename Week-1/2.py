n = 5
for i in range(n):
    print(' ' * (n - i - 1), end='')
    for j in range(n, n - i - 1, -1):
        print(j, end='')
    for j in range(n - i + 1, n + 1):
        print(j, end='')
    print()
for i in range(n - 2, -1, -1):
    print(' ' * (n - i - 1), end='')
    for j in range(n, n - i - 1, -1):
        print(j, end='')
    for j in range(n - i + 1, n + 1):
        print(j, end='')
    print()
