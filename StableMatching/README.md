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
- Perfect Stable Matching
- Stable Matching With Indifference
- Stable Roommate Matching
- Many-to-One Matching
- Many-to-Couple Matching
- Assignment Matching
- Matching With Contracts

**Applications:**
- Stable matching is used to assign medical students to their first hospitals.
- Stable matching is used by CDN to pair every used with a server, based on their
proximity. CDN perform matching once in every 10 seconds usually.
