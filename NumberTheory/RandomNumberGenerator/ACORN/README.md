**ACORN Random Number Generator**\
ACORN is the Additive COngruential Random Number generator, a family of PRNGs (Pseudo-Random Number Generators) discovered  by Roy Wikramaratna in 1984 and first published in 1989. ACORN has been implemented in various contexts, notably in GSLIB and in the NAG FORTRAN routines. Although progress may appear to have been slow, the author believes that ACORN is as strong as, or better than, most of the commonly used PRNGs.

**Mathematical Definition**

    Let the order k and the modulus M (typically an integer power of 2) be finite strictly positive integers, and let Y00 be a strictly positive 
    integer satisfying 0 < Y00 < M.

    Let   Ym0   m = 1, ..., k   be an arbitrary set of positive integer initial values each satisfying 0 ≤ Ym0 < M .
    
    Then the k-th order Additive Congruential Random Number (ACORN) generator is defined by the equations
    
    Y0n = Y0n-1          n ≥ 1                                                      (1) 
    Ymn = [Ym-1n  + Ymn-1 ] mod M     n ≥ 1, m = 1, ... , k                         (2) 
            where by  [ Y ] mod M  we mean the remainder on dividing Y by M 
    Xkn = Ykn  / M     n ≥ 1                                                        (3)
    
    The sequences Ykn and Xkn defined on [0,M) and [0,1) respectively, are the ACORN sequences of pseudo-random numbers\
    
**ACORN Initialization**\
It turns out that the numbers Xkn defined by equations (1) - (3) approximate to being uniformly distributed on the unit interval in up to k dimensions, provided a few simple constraints on the initial parameter values are satisfied:

-   the modulus M needs to be a large integer (typically a prime power, with powers of 2 offering the most straightforward implementation)
-   the seed Y00 and the modulus should be chosen to be relatively prime (two numbers are said to be relatively prime if they have no prime factors in common, which means that their greatest common divisor is 1; for M a power of two this requires only that the seed take an odd value)

        
        In practice we recommend using k > 10, M = 2^60 (for general application) or M = 2^120 (for demanding applications requiring high-quality
        pseudo-random numbers that will consistently pass all the tests in standard test packages such as TestU01) and choose any odd value less 
        than M for the seed.


**ACORN algorithm**

        Chose Parameter K
        Chose Parameter M
        Initialize seed[1 .. k]
        
        while True
            Y[1 .. k][0] = seed[1 .. k]
            Y[0][1] = Y[0][0]
            
            for i in range(2 .. k):
                Y[i][1] = (Y[i-1][0] + Y[i][1]) % M
            
            Output Y[1 .. k][1]
            seed[1 .. k] = Y[1 .. k][1]
            
    
**Useful Links**\
*The additive congruential random number generator, Roy S.Wikramaratn*\
http://acorn.wikramaratna.org/index.html
