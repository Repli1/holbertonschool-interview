#!/usr/bin/python3
"""
Function that returns the minimum amount of operations for a given int
"""

def minOperations(n):
    if (n <= 1):
        return 0
    i = 2
    while ((n % i) != 0):
        i += 1
    if (i != n):
        return minOperations(n // i) + i
    return n
