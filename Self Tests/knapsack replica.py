def knapsack(W, wt, val, n):
    k = [[0 for _ in range(W + 1)] for _ in range(n + 1)]
    # O(W * n) time and space
    for i in range(n + 1):
        for w in range(W + 1):
            # Base case
            if not i or not w:
                continue
            if wt[i - 1] > w: # It does not fit
                k[i][w] = k[i - 1][w]
            else:
                k[i][w] = max(k[i - 1][w], val[i - 1] + k[i - 1][w - wt[i - 1]])
    return k[-1][-1]

# Restrict the space complexity to O(W)
def betterKnapsack(W, wt, val, n):
    k = [0 for _ in range(W + 1)]
    # O(W * n) time and O(W) space
    for i in range(n + 1):
        for w in range(W, -1, -1):
            # Base case
            if not i or not w:
                continue
            if wt[i - 1] > w: # It does not fit
                k[w] = k[w]
            else:
                k[w] = max(k[w], val[i - 1] + k[w - wt[i - 1]])
    return k[-1]

# Test cases
val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
# Expected: 220
print(betterKnapsack(W, wt, val, n))
assert betterKnapsack(W, wt, val, n) == 220
assert knapsack(W, wt, val, n) == betterKnapsack(W, wt, val, n)

import random

for t in range(100):
    W = random.randint(1, 100)
    n = random.randint(1, 100)
    wt = [random.randint(1, 100) for _ in range(n)]
    val = [random.randint(1, 100) for _ in range(n)]
    assert knapsack(W, wt, val, n) == betterKnapsack(W, wt, val, n)