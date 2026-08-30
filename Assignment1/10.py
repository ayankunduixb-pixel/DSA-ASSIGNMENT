def mergeSorted(arr1,arr2):
    m,n = len(arr1),len(arr2)
    i=j=0
    merged = []
    while(i<m and j<n):
        if(arr1[i] <= arr2[j]):
            merged.append(arr1[i])
            i +=1
        else:
            merged.append(arr2[j])
            j +=1

    merged.extend(arr1[i:])
    merged.extend(arr2[j:])
    return merged

# Example Usage
arr1 = [1,3,5,7]
arr2 = [2,4,6,8,10]

print("Merged sorted array: ",mergeSorted(arr1,arr2))