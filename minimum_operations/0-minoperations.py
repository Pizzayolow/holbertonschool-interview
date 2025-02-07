#!/usr/bin/python3
"""A minimal operations algorithm"""

def minOperations(n):
    """An algorithm that defines the minimum amount of ops"""
    test = 0
    i = 2
    
    while i <= n:
        while n % i == 0:
            test += i
            n = n // i
        i += 1
        
    return test
