rows,cols = map(int(input("Enter rows and columns: ").split()))
matrix = []
for i in range(rows):
    row = int(input("Enter matrix elements row-wise: "))
    matrix.append(row)
zero_count = sum(row.count(0) for row in matrix)
if(zero_count > (rows * cols)//2):
    print("Matrix is sparse.")

else:
    print("Matrix is not sparse.")
