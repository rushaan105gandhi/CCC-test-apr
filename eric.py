#!/bin/python3

import math
import os
import random
import re
import sys

parent = []
def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]
def union(x, y):
    px = find(x) 
    py = find(y)
    if(px == py):
        return False
    parent[px] = py
    return True
def tasks(n, a, b):
    global parent
    parent = [x for x in range(n+1)]
    c=0
    for x,y in zip(a,b):
        if(not union(x,y)):
            c+=1
    return n  - c


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a_count = int(input().strip())

    a = []

    for _ in range(a_count):
        a_item = int(input().strip())
        a.append(a_item)

    b_count = int(input().strip())

    b = []

    for _ in range(b_count):
        b_item = int(input().strip())
        b.append(b_item)

    res = tasks(n, a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
