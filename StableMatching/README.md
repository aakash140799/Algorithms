**Problem:    Stable Matching problem**

The Stable Matching problem is given by, we are given two sets of objects. Each object in one set has preferences for objects over other set.
We want to match objects from one set to other set, similar to a bipartite graph, such that the matching is a complete stable matching. To understand complete stable matching, let us understand unstable pairing and complete matching.

**Unstable pairing:**
let (l1,r1), (l2, r2) be two pairs of object from matching, that are matched to each other.
consider the condition that l1 prefers r2 over r1, and r2 prefers l1 over l2. In
such condition, l1 and r2 both will be willing to pair with each other, which forms an unstability.
In a stable matching, there should be no unstable pairing.

**Complete matching:**
A matching is complete, if every object on left side is paired with at least one object
on right side, and vice-versa.

**Variants:**
There are quite a number of variants of stable matching given by:
- **Stable Marriage Problem**

    Stable marriage problem is given by, we are given two set of people of **equal size**. Each person in one set has **strict order of 
    preference** for every person in other set. We want to match each person from left side to **exactly one** person on right side and vice-versa. We want to find a complete stable matching.
       
- **Stable Marriage With Indifference**

    Stable Marriage is given by, we are given a stable marriage problem, but unlike tradition stable marriage, a person can prefer **two
    or more persons equally**. Such a condition is called *Indifference*.
    
- **Stable Roommate Matching**
    
    In a given instance of the stable-roommates problem (SRP), each of 2n participants ranks the others in strict order of preference. A matching is a set of n disjoint pairs of participants. A matching M in an instance of SRP is stable if there are no two participants x and y, each of whom prefers the other to their partner in M. Such a pair is said to **block** M, or to be a **blocking pair** with respect to M.
    
- **Hospital/Resident Problem**


    In Hospital/Resident Problem, we are given a list of hospitals and doctors(possibly of unequal sizes). Each hospital has a strict
    order of preference for the set of doctors, same goes for doctors. Each hospital has a limited number of seats to accomodate. We
    want to find a many-to-one stable matching. Note that, some hospitals may be left partially filled or some doctors may be left unmatched.
    
    
- **Hospital/Resident Couple problem**


    Hosiptal/Resident Couple problem is similar to Hospital/Resident Problem, with one extra condition. We are also given a set of
    one-to-one pairing of doctors. Two doctors in a pair always want to be matched to same hospital. This is similar to condition,
    when a married doctors pair want to get addmitted in same hospital.
    
    
- **Assignment Matching**

    The problem instance has a number of agents and a number of tasks. Any agent can be assigned to perform any task, incurring some cost that may vary depending on the agent-task assignment. It is required to perform as many tasks as possible by assigning at most one agent to each task and at most one task to each agent, in such a way that the total cost of the assignment is minimized.
    
    
- **Matching With Contracts**


    Yet to be added


**Applications:**
- Stable matching is used to assign medical students to their first hospitals.
- Stable matching is used by CDN to pair every used with a server, based on their
proximity. CDN perform matching once in every 10 seconds usually.


**Refering:**

For complete information, you may want to see
-   College Admissions and the stability of marriage
-   Algorithms Design
-   An efficient algorithms for "Stable roommate" problem