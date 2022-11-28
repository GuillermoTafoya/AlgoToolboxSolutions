# An step by step implementation of the coin change problem using dp

def coin_change(coins, amount):
    # initialize the dp table
    dp = [0] + [float('inf')] * amount
    # loop through the amount
    for i in range(1, amount + 1):
        # loop through the coins
        for coin in coins:
            # if the coin is less than the amount
            if coin <= i:
                # update the dp table
                dp[i] = min(dp[i], dp[i - coin] + 1)
    # return the result
    return dp[amount] if dp[amount] != float('inf') else -1
    # O(n * m) time complexity, where n is the amount and m is the number of coins
    # O(n) space complexity, where n is the amount

# Test
coins = [1, 2, 5]
amount = 11
print(coin_change(coins, amount))
assert coin_change(coins, amount) == 3

coins = [2]
amount = 3
print(coin_change(coins, amount))
assert coin_change(coins, amount) == -1