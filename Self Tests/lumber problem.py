from collections import defaultdict
count = 0
globalL = 0
def main(arr,L):
    global count
    global globalL
    globalL = L
    arr.sort()
    memo = defaultdict(int) # Memoization
    while arr:
        currentLog = arr.pop()
        memo[L] += helper(arr,L,currentLog,memo)
    return memo[L]

def helper(arr,L,currentLog,memo):
    global count
    print("Current Log: ",currentLog)
    print("Remaining Logs: ",arr)
    print("L: ",L)
    if L in memo and L != globalL:
        return memo[L]
    if L == 0: # The log was consumed
        return 1
    remainingLog = L - currentLog
    print("Remaining Log: ",remainingLog)
    if remainingLog in arr:
        count += 1
        arr.remove(remainingLog)
        memo[L] += 1
        return memo[L]
    else:
        arrCopy = arr.copy()
        memo[L] = float('inf')
        for i in range(len(arrCopy)):
            currentLog = arrCopy[i]
            if currentLog <= remainingLog:
                # Try to consume the remaining log, mantain the best result
                passArr = arr.copy()
                passArr.remove(currentLog)
                tryResult = helper(passArr,remainingLog,currentLog,memo)
                if tryResult < memo[L]:
                    memo[L] = tryResult
                    bestLog = currentLog
        if memo[L] != float('inf'):
            arr.remove(bestLog)
            
        
        return memo[L]
        




if __name__ == "__main__":
    arr = list(map(int,input().split()))
    L = arr.pop()
    print(main(arr,L))
