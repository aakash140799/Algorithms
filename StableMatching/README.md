Problem:    Stable Matching problem

We are given a left set of people of size n, and a right set of people of same size. Each person has a preference list for
people on other side. We want to pair each left person with a right person such that we find a complete stable matching.
To understand a complete stable matching, let us focus on a few points

**Unstable pairing:**
let (l1,r1), (l2, r2) be two pairs of men and women, that are matched to each other.
consider the condition that l1 prefers r2 over r1, and r2 prefers l1 over l2. In
such condition, both will be willing to pair with each other, which forms an unstability.
In a stable matching, there should be no unstable pairing.

**Complete matching:**
A matching is complete, if every person on left side is paired with at least one person
on right side, and vice-versa.

**NOTE: One person is matched with only one person**

**Applications:**
- Stable matching is used to assign medical students to their first hospitals.
- Stable matching is used by CDN to pair every used with a server, based on their
- proximity. CDN perform matching once in every 10 seconds usually.
