#!/usr/bin/python3

def minOperations(n):
    if (n <= 1):
        return 0
    i = 2
    while ((n % i) != 0):
        i += 1
    if (i != n):
        return minOperations(n // i) + i
    return n
