# Read matrix size
rows, cols = map(int, input("Enter rows and columns: ").split())

# Read matrix elements
matrix = []
print("Enter matrix elements row-wise:")
for i in range(rows):
    row = list(map(int, input().split()))
    matrix.append(row)

# Read rows to interchange
r1, r2 = map(int, input("Enter two row indices to interchange (0-based): ").split())

# Swap rows
matrix[r1], matrix[r2] = matrix[r2], matrix[r1]

print("Matrix after interchanging rows:")
for row in matrix:
    print(row)
