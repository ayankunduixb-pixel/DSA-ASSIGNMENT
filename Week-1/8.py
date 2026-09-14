def reverse(arr,start,end):
    while (start < end):
        arr[start],arr[end] = arr[end],arr[start]
        start +=1
        end-=1

def rotateLeft(arr,k):
    n = len(arr)
    k = k%n
    reverse(arr,0,k-1)
    reverse(arr,k,n-1)
    reverse(arr,0,n-1)

def rotateRight(arr,k):
    n = len(arr)
    k = k % n
    reverse(arr,0,n-1)
    reverse(arr,0,k-1)
    reverse(arr,k,n-1)

# Emaple Usage
arr = [1,2,3,4,5,6,7]
k = 2
rotateLeft(arr,k)
print(f"Left rotation by {k} : {arr}")

arr = [1,2,3,4,5,6,7]
k = 2
rotateRight(arr,k)
print(f"Right rotation by {k} : {arr}")