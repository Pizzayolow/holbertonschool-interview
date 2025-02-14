#!/usr/bin/python3
"""
function makeChange.
"""

def makeChange(coins, total):
    """Make change for a given total using the fewest number of coins.
    Args:
        coins: integer list
        total: int, total amount of change to make
    Return
        nteger
    """
    if total <= 0:
        return 0
    number = [float('inf')] * (total + 1)
    number[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            number[i] = min(number[i], number[i - coin] + 1)

    return number[total] if number[total] != float('inf') else -1
