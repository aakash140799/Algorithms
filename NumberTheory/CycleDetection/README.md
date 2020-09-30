**Cycle Detection**\
Let us assume F be a function that maps a finite set S to itself. We are given a starting value x0
in S, let us perform a series of operations given by

    x0 = x0, x1 = F(x0), x2 = F(x1), x3 = F(x2), ..., xn = F(xn)

Since S is a finite set, it is guraanted that eventually we will find two indices i and j, such
that xi == xj. We want to find xi, and smallest j such that xi == xj.

This problem can also be reduced to finding cycle in directed graph. We need to map each element
in set S to an vertex in graph G, and there is an edge between Vi -> Vj, iff xj == F(xi).
We are given the starting vertex V0, and we need to find a cycle in the directed graph found
by travelling from V0.


**Applications**\
Cycle detection problem is applicable in some fields given by
-   PseudoRandom number generator
-   number-therotic algorithm
-   collisions in cryptographic hash functions
-   deadlock detection in DBMS transactions


e.g


Let F(x) = (x^2)%7,\
S = {0,1,2,3,4,5,6}\
Let us find sequences for different x0

x0 = 2,
x1 = (2 \* 2)%7 = 4, 
x2 = (4 \* 4)%7 = 2, 
cycle found x0 == x2

x0 = 3,
x1 = (3 \* 3)%7 = 2,
x2 = (2 \* 2)%7 = 4,
x3 = (4 \* 4)%7 = 2,
cycle found x1 == x3

x0 = 5,
x1 = (5 \* 5)%7 = 4,
x2 = (4 \* 4)%7 = 2,
x3 = (2 \* 2)%7 = 4,
cycle found x1 == x3

