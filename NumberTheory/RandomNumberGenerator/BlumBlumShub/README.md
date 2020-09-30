**Blum Blum Shub**\
Blum Blum Shub (B.B.S.) is a pseudorandom number generator proposed in 1986 by Lenore Blum, Manuel Blum and Michael Shub that is derived from Michael O. Rabin's one-way function. The cryptographic security of the Blum-Blum-Shub PRBG follows from an assumption on a number-theoretic problem, the so-called quadratic residuosity problem.

**Definitions**\
*Quadratic Residues*

    Let n ∈ N. Then a ∈ Z∗n is called a quadratic residue modulo n if there exists b ∈ Z∗n such that a ≡ b2 (mod n). 
    The set of quadratic residues modulo n is denoted by QRn. Furthermore, QNRn := Z∗n \ QRn is called the set of 
    quadratic non-residues

*Legendre symbol*

    Let p be an odd prime. For a ∈Z∗ p, the Legendre symbol (a/p) is deﬁned as 
    
                    (a/p) = 0 if p | a
                            1 if a ∈ QRp
                           -1 if a ∈ QNRp

*Jacobi symbol*

    Let n be an odd integer with prime factorization
    
    n = mul(pi ^ ei) over i
    
    Let a ∈ Z∗n. Then the Jacobi symbola (a/n) is deﬁned by
    
    (a/n) = mul( (a/pi) ^ ei ) over i
    

**Theorms**

-   Let p be a prime and α a non-zero element of Z∗p; then we have -a = a <=> p = 2
-   For p, an odd prime and for α, β, non-zero elements of Z∗ p, we have α^2 = β^2 ⇐⇒ α = β ∨α = −β
-   Let n = p1 ·p2 ·...·pk, where p1, ..., pk are distinct odd primes and k ≥ 2. An element α of Z∗n is a quadratic residue modulo n if and only if each component of its CRT transform with respect to the moduli p1,...,pk is a quadratic residue of Z∗ pi, where pi is the modulus corresponding to that component.
-   Let n = p·q be the product of two Blum primes. Let a ∈ QRn. Then a has exactly four square roots, exactly one of which is in QRn itself.
-   Let n = p·q be the product of two Blum primes. Let a ∈ QRn. Then √a denotes the square root of a such that √a ∈ QRn.


**Algorithm**

    Generate p and q, two big prime numbers, such that p%4 == 3, and q%4 == 3
    n := p·q
    Choose s ∈R [1,n−1], the random seed
    x0 := s2 (mod n)
    The sequence is deﬁned as xi := (xi−1)^2(mod n) and zi := parity(xi)
    The output is z1,z2,z3,...
    
    
**Papaers**\
*Cryptographic Secure Pseudo-Random Bits Generation : The Blum-Blum-Shub Generator*