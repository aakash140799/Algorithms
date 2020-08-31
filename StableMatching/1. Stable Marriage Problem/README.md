**Problem : Stable Marriage problem**

Stable marriage problem is given by, we are given two set of people of **equal size**. Each person in one set has **strict order of 
preference** for every person in other set. We want to match each person from left side to **exactly one** person on right side and vice-versa. We want to find a complete stable matching.
   
   
**Solved by : Gale Shapely Algorithm**
   
   
**Theory:**
    
Each person on left side propose people on right side one-by-one, in order of their preference list.
Person of right side accepts/rejects the proposal if it is more preferable to them than his current proposal.
After every person on left side and right side have a pairing, we get a complete stable matching.

Let us see how this intiution solves 1) Stable matching 2) complete matching

*Stable matching*

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

*Compelte Mathcing*

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
side gets the worst pairing they can have i.e algorithm is **proposer-favoring** and **proposed-permisive**.


**Refer:**

To know more, please go through the original paper : *college admission and the stability of marriage*