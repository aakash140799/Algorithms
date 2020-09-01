**Problem : Stable Roommate Problem**

stable-roommate problem is the problem of finding a stable matching for an even-sized set. A matching is a separation of the set into disjoint pairs ("roommates"). The matching is stable if there are no two elements which are not roommates and which both prefer each other to their roommate under the matching. This is distinct from the stable-marriage problem in that the stable-roommates problem allows matches between any two elements, not just between classes of "men" and "women". 


It is commonly stated as: 

In a given instance of the stable-roommates problem (SRP), each of 2n participants ranks the others in strict order of preference. A matching is a set of n disjoint pairs of participants. A matching M in an instance of SRP is stable if there are no two participants x and y, each of whom prefers the other to their partner in M. Such a pair is said to block M, or to be a blocking pair with respect to M.

**Solved By : Algorithm given by Robert. W. Irving**

**Theory:**

The algorithm breaks down naturally into two phases.

**First Phase**

- An individual x proposes other in the order in which they appear in his preference list, untill some y keeps his proposal for
consideration. Later y may reject his proposal, which lead to x again start giving proposals.

- x may receive proposal from some y. If its appealing, x may choose to accept his proposal, rejecting some other inferior proposal.


The algorithm terminates with 
1)  either all having one proposal from someone else
2)  one having his preference list emptied.

if condition 2 is met, then there is no stable matching.To understand this, let us focus on a collary.

col 1)  *If y rejects x during proposal making, then (x, y) can not be part of any stable matching M.*

To prove this, let us assume that among all rejects of stable pair, (x, y) was the first. Since y rejected x, y must
have gained a better proposal from say, z. Since (x, y) is a stable pair, we can find a stable matching M that contains (x, y).
Now in M, since y prefers z over x, to maintain stability in M, z must be paired with say w, such that z prefers w over y.
Since z ended up proposing y, z must have been rejected by w previously, which contradicts our assumption that (x, y) is
the first stable pair of reject.


Hence, condition 2 is met, col1 says we can not have any stable matching.

col 2)   *if at any stage of proposal, x proposes to y, then*

col2.1
- *x can not have a better partner than y.*

This is directly visible from the col1.

col2.2
- *y can not have a inferior partner than x.*

Let we have a stable matching M, in which (y, z) are paired, and y prefer x to z. since by col2.1, x also
prefer y to his current partner, we have a unstable pairing, because x and y both prefer each other over their
current partners.


col 3) * if after first stage every person end up holding a proposal, then preference list of y,
who holds a proposal from x , can be reduced using*

col3.1)
- *delete all who are inferior than x.*

col3.2)
- *delete all who hold a better proposal than y can offer to them.*

col3.3)
- *y is first on x's list and x is last on y's list.*

col3.4)
- *if a appears on b's list, then b appears on a's list.*


lemma 2) if after reduction, every person's preference list contains just one person, then
we have found a stable matching.

To prove that, let us consider person x. y is the sole person on x's list. Now (x, y) is always
a stable pair and belongs to some matching M. 

- Let y prefers w over x, but since w is not on y's preference list, w must have rejected y explicitly
or implicitly through col3.2). By col1) (y, w) can't be paired.

- Let some z prefer y over his current pair. but since z is not present on y's list, y must have rejected
z explicitly or implicitly through col3.1). By col1) (y, z) can't be paired.


**Second Phase**

Let us assume, after performing reduction from first phase, we get some person x whose preference list
contains more than one person. In such case, we need to find whether a stable matching is feasible or not.
Let us give a list reduction operation to furthur reduce the size of preference list of person.

*Reduction Operation*

- find a cycle a1, a2, a3, a4, ..., an and b1, b2, b3, ..., b4 such that 
1 for each bi, bi is second on ai-1's list and first on ai's list. For b1, b1 is second on an's list, first on a1's list. We
call such a cycle a *all or none cycle*.

2 we can represet such all or none cycle such as
    b1  b2   b3   b4    ...     bn   a1     
    ^  / ^  / ^  / ^             ^  / ^
    | /  | /  | /  |             | /  |
    a1   a2   a3   a4   ...     an   a2
    
where ai -> bi, means a1 is proposing bi, and ai -- bi means bi lies second on ai's preference list.

- Force all bi to reject their current proposal from ai's, forcing them to propose their second preference.


To understand Col4.1, Col4.2, let us understand Lemma3 give by

Lemma 3.1) * in a stable matching M contained in the reduced preference list, either all (ai, bi)
are partners or none is for all i.

Lemma 3.2) * if there is such a stable matching in (ai, bi) are partners, then there is one in which
they are not.*

To prove Lemma3.1, let (ai, bi) are partner in some stable matching. 
1 since ai is proposing bi, by Col3.3, ai must be last on bi's preference list. 
2 since bi is second on ai-1's preference list, by Col3.4, bi's preference list must contains ai-1.
3 by 1, bi prefer ai-1 over ai. To keep the matching stable, ai-1 must be partners with bi-1, since ai-1
prefer only bi-1 over bi.
4 hence following the arguments, all (ai, bi) must be paired

- Let A = {a1, ..., an} and B = {b1, ..., bn}. If A ^ B != NULL, then there is some ak == bj, then
it is impossible for ak to have its first preference, then by lemma3.1, A ^ B != NULL, implies that
none of ai and bi can be partners, so we may assume that A ^ B == NULL.

- Suppose that M is a stable matching, in which all ai and bi are partners. Let us consider matching M'
in which all ai are partnered with bi+1
1 Clearly each person in B obtain a better person, since ai was last on their preference list. Only person
having worse partners are in A, hence instability if exists must be in A.

if ai prefer ,say x over bi+1, then there are three conditions possible.
a)  ai and x were partners in M, hence x == bi. Since bi prefer ai-1 over ai, hence no unstability.
b)  ai also prefer x to bi, in which case x is not in ai's reduced preference list. In this case, x must
have rejected ai before by receiving a better proposal from someone elese. hence can't form a stable pairing with ai.
c)  ai prefers bi to x, hence x lies between bi and bi+1, but is not present in ai's reduced preference list. Even in that
case, x must have received a better proposal than ai, then will not be willing to pair with ai.

Col 4.1) *If the original problem instance admits a stable matching, then there is a stable matching
after applying the reduction operation.*

Col 4.2) *If one or more preference lists after applying reduction, becomes empty, then there is no stable
matching possible.*

Lemma 4) * if in a reduced set of preference list, every list contain only one person, then the lists specify
a stable matching.*


**Algorithm**

    // first phase

    // add all free roommates to queue
    make a queue
    add all roommates to queue
    
    while queue is not empty
        
        choose front roommate x from queue
        
        while x is not proposing anyone and x'preference list contain some person
        
            if x' preference list is empty:
                return "no matching found"
            
            choose front roommate y from x's preference list
            if y is free
                x proposes y
            elif y is having inferior proposal
                y reject its current proposal
                x proposes y
            else
                remove y from x's preference list
        
        
    for each roommate y
        x is proposing y
        remove from y's preference list all roommate inferior to x
        remove from y's preference list all roomate having better proposal than y offers
        
    // phase two
    do
        if all x have single roommate in preference list
            return "matching found"
        
        add all x having more than one preference list in queue
        find all or none cycle in queue
        all bi in all or none cycle reject ai, and reduce preference list  
        
    while no x have a empty preference list
    
    if some x have empty preference list
            return "no matching found"
            
            
**Time Complexity: O(n ^ 2)**

**Space Complexity: O(n ^ 2)**

**Refer:**

to know more, please go through the original paper : *An efficient algorithm for solving stable roommate problem*.