**Problem : Stable Marriage problem with Indifference**

Given two sets of person of **equal size**. We want to match each person on left set to **exactly one person**
to right set, to get a complete stable matching. Unlike traditional stable marriage, a person is allowed to
prefer one or more persons equally. This notion of indifference creates three notions of stable matching
given by.
    
**Weakly Stable Matching**
    
A matching is weakly stable, if we can't find two pairs (l1, r1), (l2, r2) in matching M such that l1 **strictly prefers**
r2 over r1, and r2 **stricly prefers** l1 over l2. The original GaleShaply algorithms can be used to find a
weakly stable matching by breaking indifferent ties arbitrarly.
    
**Strongly Stable Matching**

A matching is strongly stable, if we can't find two pairs (l1, r1), (l2, r2) in matching M such that l1 **strictly prefers**
r2 over r1, and r2 **strictly or equally prefers** l1 over l2. Unlike stable marriage problem, it is possible that a strongly stable matching **may not exist**. 

The original GaleShaply algorithm can by modified to find such a matching, if it exists.
    
**Super Stable Matching**

A matching is super stable, if we can't find two pairs (l1, r1), (l2, r2) in matching M such that l1 **stricly or equally
prefers** r2 over r1, and r2 **stricly or equally prefers** l1 over l2. Unlike stable marriage problem, it is possible
that a super stable matching **may not exist**.

We can modify GaleShaply algorithms such that it checks for super-stable matching, and outputs one if it exits
    
    
**Algorithm : modified Gale Shapely Algorithm**

    This algorithm solves stable marriage problem with indifference for three notion of stability.
    
    
**Theory:**

-   Weakly Stable Matching

    We can run a noraml GaleShaply algorithm. To break ties for given person li, we can rank each ri in preference list of
    li by order of their rank, then by their person number. Such that among ri having equall rank, ri having lower person number
    if more preferable and so on.
    
-   Strongly Stable Matching

    
    Each person on left side propose people on right side one-by-one, in order of their preference list.
    Person of right side accepts/rejects the proposal if it is more preferable to them than his current proposal.
    After every person on left side and right side have a pairing, we get a complete stable matching.
    
    Let us see how this intiution solves 1) Stable matching 2) complete matching

    Stable matching
        To see how an unstable matching be formed, let us consider the conditions that form
        an unstable matching.
        1)  there are two pairs (l1, r1), (l2, r2).
        2)  l1 is willing to pair up with r2.
        3)  r2 is also willing to pair up with l1
        To form an unstable matching, all three conditions must be satisfied.

        To see how algorithm provides a stable matching.
        Let us condsider the mathcing M found after running the algorithm.

        consider any person li on left side set who is paired up with person ri.
        let us see how li is paired with ri.

        1) Acc. to algorithm, li must have proposed all rj being more preferable(to li)
        than ri. Since li is not paired with any such rj, then all such rj must have
        accepted a more preferable(to rj) lj.
        Hence rj are not willing to pair with li, condition 3 fails.

        2) Acc. to algorithm, li did not proposed all rj being lower preferable(to li)
        than ri.
        Hence li is not willing to pair with any such rj, condition 2 fails.

        Hence in matching M, for every pairing, either codition 2 or 3 fails, so
        unstable matching is found.

    Compelte Mathcing
        Let us consider matching M found after running the algorithm
            1) Since every person on left side is paired with exactly one person.
            2) There are equal number of person on both sides.
        Every person on both sides must be paired up.



**Algorithm:**

    make a queue
    add all free left person in queue

    while queue is not empty
        front person proposes its top unproposed person
            if right person is unpaired
                pair them up
            if right person is paired, but prefers front more
                pair them up
                add unpaired person to queue
            else
                continue



**Time Complexity: O(n^2)**
**Space Complexity : O(n^2)**



**Note:**
    
In this algorithm, the proposing sides gets best pairing they can have, while proposed
side gets the worst pairing they can have i.e algorithm is **proposer-favoring** and **proposed-permissive**.
    
**Refer:**

To know more, please go through the original paper - *college admission and the stability of marriage*