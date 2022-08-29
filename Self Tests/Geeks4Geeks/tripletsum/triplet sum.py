def findTriplets(arr, n):
    #Create a hash map with complements
    
    for i in range(len(arr)-2):
        for j in range(i+1,len(arr)-1):
            for k in range(j+1,len(arr)):
                if arr[i]+arr[j]+arr[k] == 0:
                    print(i,j,k)
                    return True
    return False

n = int(input())
arr = list(map(int,input().split()))
print(findTriplets(arr, n))

