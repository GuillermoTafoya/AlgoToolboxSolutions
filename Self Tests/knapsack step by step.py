# An step by step implementation of knapsack problem using dp

def knapsack(W, wt, val, n):
    # The variables are:
    # W: the capacity of the knapsack
    # wt: the weight of each item
    # val: the value of each item
    # n: the number of items

    # First, we create a 2D array to store the results of subproblems
    # Each entry for the column represents the weight of the item
    # Each entry for the row represents the weight of the knapsack
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]

    # Build table K[][] in bottom up manner
    for i in range(n + 1):
        for w in range(W + 1):
            # First, we check if the item is 0 or the weight of the knapsack is 0
            # This is the base case
            if i == 0 or w == 0:
                K[i][w] = 0
            # If the weight of the item is greater than the weight of the knapsack
            # We cannot include the item in the knapsack
            elif wt[i - 1] > w:
                K[i][w] = K[i - 1][w]
            # If the weight of the item is less than or equal to the weight of the knapsack
            # We can include the item in the knapsack
            else:
                # We check if the value of the item plus the value of the remaining weight
                # is greater than the value of the item without the remaining weight
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w])

    # We return the last entry of the table, which is the maximum value
    return K[n][W]

# Test cases
val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
# Expected: 220
print(knapsack(W, wt, val, n))
assert knapsack(W, wt, val, n) == 220
