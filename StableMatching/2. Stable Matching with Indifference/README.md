**Problem : Stable Marriage problem with Indifference**

Given two sets of person of **equal size**. We want to match each person on left set to **exactly one person**
to right set, to get a complete stable matching. Unlike traditional stable marriage, a person is allowed to
**prefer one or more persons equally**. This notion of indifference creates three notions of stable matching
given by.
    
    
    
- **Weakly Stable Matching**
    
A matching is weakly stable, if we can't find two pairs (l1, r1), (l2, r2) in matching M such that l1 **strictly prefers**
r2 over r1, and r2 **stricly prefers** l1 over l2. The original GaleShapley algorithms can be used to find a
weakly stable matching by breaking indifferent ties arbitrarly.
    
    
    
- **Strongly Stable Matching**

A matching is strongly stable, if we can't find two pairs (l1, r1), (l2, r2) in matching M such that l1 **strictly prefers**
r2 over r1, and r2 **strictly or equally prefers** l1 over l2. Unlike stable marriage problem, it is possible that a strongly stable matching **may not exist**. 
The original GaleShapley algorithm can by modified to find such a matching, if it exists.
    
    
    
- **Super Stable Matching**

A matching is super stable, if we can't find two pairs (l1, r1), (l2, r2) in matching M such that l1 **stricly or equally
prefers** r2 over r1, and r2 **stricly or equally prefers** l1 over l2. Unlike stable marriage problem, it is possible
that a super stable matching **may not exist**.
We can modify GaleShapley algorithms such that it checks for super-stable matching, and outputs one if it exits
    
    
    
    
**Solved by : modified Gale Shapeley Algorithm**

  
  
**Theory:**

-   *Weakly Stable Matching*

    We can run a noraml GaleShapley algorithm. To break ties for given person li, we can rank each ri in preference list of
    li by order of their rank, then by their person number. Such that among ri having equall rank, ri having lower person number
    is more preferable and so on.
    
-   *Super Stable Matching*

    The proposal sequence proceeds in the usual way, except that a free man who has two or more women tied at the head of his current list proposes to all of them simultaneously. When a woman receives a proposal, all men strictly inferior to the proposer are deleted from her list, and she from theirs, but she may hold more than one proposal if the men in question are tied in her list. The proposal sequence may terminate with one or more of the men’s lists empty, in which case no super-stable matching exists. Otherwise, each man will be engaged to one or more women, and the fiancC(e)s of any multiply engaged person must be tied in his/her list. As we will show, no woman who is multiply engaged at this point can have a super-stable partner from among any of her fiances, nor from among any men who may be tied with them in her list. So all such pairs may be deleted and the proposal sequence re-activated. The whole process is repeated until it produces a one-one engagement mapping, which will be a super-stable matching, or until some man’s list becomes empty, indicating that no super-stable matching is possible.
    

-   *Strongly Stable Matching*

    Each proposal sequence proceeds, as in the super-stable case, until some man’s list becomes empty, in which case there can be no strongly stable matching, or until all the men are engaged. In the latter case, if the bipartite graph representing the engaged pairs contains a perfect matching-i.e., if all the men and women can be paired off on a one-one basis with a fiance(e)-then the resulting matching is strongly stable.

**Algorithm:**

*Weakly Stable Matching:*
same as stable marriage with modified preferences.

*Super Stable Matching*

    make a queue
    add all left person li in queue

    while queue is not empty
        li := queue.front
        for each ri in li's top preference:
            if ri is free:
                create pair(li, ri)
            elif ri is paired with lj having lower preference than li
                create pair(li, ri)
                delete all pair(lj, ri) such that lk is lower prefered
                if lj is free, add to queue
    
    if all li's and ri's are single paired
        return the stable matching
    elif some li have empty preference list
        return no matching found
    else
        for each li:
            if li is muliple paired
                delete all pair(li, rj)
        for each ri:
            if ri is multiple paired
                delete all pair(lj, ri)
        repeat


*Strongly Stable Matching*

    make a queue
    add all left person li in queue
    
    while queue is not empty
        li := queue.front
        for each ri in li's top preference:
            if ri is free:
                create pair(li, ri)
            elif ri prefers li:
                create pair(li, ri)
                delete all pair(lj, ri), such that lj is lower prefered
                if lj is free, add to queue
        
    if bipartite graph given by engagements of l and r set have a perfect matching
        return perfect matching
    elif some li have empty preference list
        return no strongly stable matching
    else
        find critical section in bipartite graph
        delete all pair in critical section
        repeat


**Time Complexity: O(n^2)**


**Space Complexity : O(n^2)**



**Note:**
    
In this algorithm, the proposing sides gets best pairing they can have, while proposed
side gets the worst pairing they can have i.e algorithm is **proposer-favoring** and **proposed-permissive**.
    
    
**Refer:**

To know more, please go through the original paper - *Stable marriage and Indifference*