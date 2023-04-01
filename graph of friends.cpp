#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'maxShared' function below.
#
# The function is expected to return an INTEGER.
# The function accepts WEIGHTED_INTEGER_GRAPH friends as parameter.
#

#
# For the weighted graph, <name>:
#
# 1. The number of nodes is <name>_nodes.
# 2. The number of edges is <name>_edges.
# 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
#
#

def maxShared(friends_nodes, friends_from, friends_to, friends_weight):
    # Write your code here
    res = {}                                                 # Edge frequency’s dictionary
    for i in range(len(friends_from)):          # for range of length of friends_from
       a = min(friends_from[i], friends_to[i])
       b = max(friends_from[i], friends_to[i])
       # Edge is given if in case it is not present already
       if res.get((a, b)) is None:
           res[(a, b)] = 1
       else:
           # Otherwise frequency is incremented
           res[(a, b)] += 1
    Ans = 0
    max_Connection = 0
    # Maximum no. of connection is searched
    for Edge in res.keys():
       max_Connection = max(max_Connection, res[Edge])
    # Maximum product of edge and maximum connection is found
    for Edge in res.keys():
       if res[Edge] == max_Connection:
           Ans = max(Ans, Edge[0] * Edge[1])
   # Output is returned
    return Ans
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    friends_nodes, friends_edges = map(int, input().rstrip().split())

    friends_from = [0] * friends_edges
    friends_to = [0] * friends_edges
    friends_weight = [0] * friends_edges

    for i in range(friends_edges):
        friends_from[i], friends_to[i], friends_weight[i] = map(int, input().rstrip().split())

    result = maxShared(friends_nodes, friends_from, friends_to, friends_weight)

    fptr.write(str(result) + '\n')

    fptr.close()
