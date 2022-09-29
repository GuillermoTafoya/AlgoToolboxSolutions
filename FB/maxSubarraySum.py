# Return the max subarray sum of an array, it includes negative numbers
def solve(arr):
    maxSum = -float('inf')
    currentSum = 0
    for i in range(len(arr)):
        currentSum += arr[i]
        if currentSum > maxSum:
            maxSum = currentSum
        if currentSum < 0:
            currentSum = 0
    return maxSum

if __name__ == "__main__":
    with open("candy_collection_output.txt", "w") as f:
        f.write("")
    with open("candy_collection_input.txt", "r") as f:
        testcases = int(f.readline())
        for i in range(testcases):
            n = int(f.readline())
            arr = list(map(int,f.readline().split()))
            with open("candy_collection_output.txt", "a") as f2:
                f2.write("Case #" + str(i+1) + ": " + str(solve(arr)) + "\n")
    print("Done")
