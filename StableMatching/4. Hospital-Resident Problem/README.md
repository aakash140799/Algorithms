**Problem : Hospital/Residents Matching**

We are given a list of hospitals of size n, a list of residents of size m. Each resident creates a preference list for hospitals, not
necessarly including all hospitals in his list. Each resident is having a rank, such that hospitals prefer high ranked residents. Each hospital
is having a capacity room for hi residents. We need to assign residents to hospitals such that
-   no hospital is assigned more residents than its capacity room
-   no resident is assigned more than one hospitals(possible zero).
-   there is no blocking pair existing in matching.
A pair(hi, rj) is said to block matching M, if there exists rk, such that rk is either unassigned or prefers hi over hk, and
rk is more prefered than a least one assignement of hi.

**Solved By: Gale-Shaply Algorithm**

Each resident ri propose the hospital hi in each preference list. If hi is under-assigned, ri is assigned to hi. Else if
hi is full, but ri is prefered over a least one assignment of hi, hi rejects its least ranked assignment and accepts ri.

**Algorithm :**

    M = null
    while (there is some unassigned ri and ri has non-empty list)
        hj = top hospital on ri's list
        
        M := M V (ri, hj)
        if(hj is over-assigned)
            rk = worst assignment of hj
            M := M - (rk, hi)
        if(hj is full)
            rk = worst assignment of hi
            for each rl of rk on hi's list
                delete the pair(rl, hi)


**Key Results :**
-   A pair(ri, hj) is acceptable if hj appears on ri's preference list. Let A be the set of acceptable pairs and
L = |A|. Given an instance of HR, the algorithm constructs in O(L) time, the unique stable matching in which each
assigned resident obtains the best hospital that he could obtain in any stable matching, whilst each unassigned
resident is unassigned in every stable matching.
-   each hospital are assigned same number of residents in each stable matching.
-   any hospital that is under assigned in a stable matching, remains under-assigned in every stable matching.

**Extension :**

The extension of HR problem may include indifferent preference ties, called HRT. A hospital may be indifferent among a set of residents.
In this context, three stablity definitions arise : weakly stable, super stable, strongly stable. 
-   Given an instance of HRT, weakly stable matching may have different sizes and determining a maximum sized weakly stable matching is NP-Hard.
-   On the other hand, a super stable matching need not exist, but it can be found using an O(L) algorithm, if it exists.
-   In strongly stable matching, a strongly stable matching can be found using O(L^2) algorithm, if it exists.

**Application :**
-   Used to assigne hospitals/university to fresh-doctors/students according to their ranking and preference list.


**Read more :**
To read more, you may like to go through the original paper : *The Hospital/Residents problem*.