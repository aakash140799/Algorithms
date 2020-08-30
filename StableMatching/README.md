**Problem:    Stable Matching problem**

The Stable Matching problem is given by, we are given two sets of people : left set and right set. We want
to match people from left set to people in right set, such that we find a Complete Stable matching. To understand complete
stable matching, let us focus on few points.

**Unstable pairing:**
let (l1,r1), (l2, r2) be two pairs of men and women, that are matched to each other.
consider the condition that l1 prefers r2 over r1, and r2 prefers l1 over l2. In
such condition, both will be willing to pair with each other, which forms an unstability.
In a stable matching, there should be no unstable pairing.

**Complete matching:**
A matching is complete, if every person on left side is paired with at least one person
on right side, and vice-versa.

**Variants:**
There are quite a number of variants of stable matching given by:
- **Stable Marriage Problem**


    In Perfect Stable Matching/Stable Marriage Problem, we are given two set of men and women of equal sizes. Each man has
    a strict order of preference for the set of women, same goes for every women. We want to find a one-to-one complete stable
    matching.
    
    
- **Stable Matching With Indifference**


    In Stable Matching With Indifference, we are given two set of men and women of equal sizes. But a man can have weak order
    of preference for the set of women. Such that he is indifferent between some subset of women, Same goes for women. in such
    a case, we can find a one-to-one complete weak-stable matching, such that no (men, women) strictly prefer each other over their
    partner.
    
    
- **Stable Roommate Matching**
    
    
    In Stable Roommate mathcing, (unlike tradition stable matching problem) we are given a single set of even size. We want to find
    a one-to-one complete stable matching in the same set.


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
