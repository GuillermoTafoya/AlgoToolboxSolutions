
def solution(A):
    # We can count repetitions in an dict. Then pic the two such that they repeat at least 2 times and are the least distant
    # First we count the repetitions in the array
    count = dict()
    for i in A:
        count[i] = count.get(i, 0) + 1
    # If an element repeats 4 times, we can pair it with itself. Hence return 0
    # Now we search for the two elements that repeat at least twice and are the least distant
    minDiff = float("inf")
    keys = list(count.keys())
    for leftPointer in range(len(keys)):
        val = count[keys[leftPointer]]
        if val >= 4:
            return 0
        if val >= 2:
            for j in range(leftPointer+1, len(keys)):
                if count[keys[j]] >= 2:
                    minDiff = min(minDiff, abs(keys[leftPointer]-keys[j]))
    print()
    return minDiff if minDiff != float("inf") else -1


if __name__ == '__main__':
    A = [911,1,3,1000,1000,2,2,999,1000,911] # Expected 89: 1000-911=89
    print(solution(A)) 
    A = [2,2,2,2,2] # Expected 0: 2-2=0
    print(solution(A))
    A = [173, 168, 177, 159, 159, 161, 155, 173, 176, 170, 165, 155, 159, 154, 173, 174, 169, 172, 161, 160, 178, 156, 152, 172, 178, 179, 176, 157, 167, 168]