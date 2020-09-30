**Random Number Generators**\
A pseudorandom number generator (PRNG), also known as a deterministic random bit generator (DRBG), is an algorithm for generating a sequence of numbers whose properties approximate the properties of sequences of random numbers. The PRNG-generated sequence is not truly random, because it is completely determined by an initial value, called the PRNG's seed (which may include truly random values). Although sequences that are closer to truly random can be generated using hardware random number generators, pseudorandom number generators are important in practice for their speed in number generation and their reproducibility.


**Problems With Deterministic Generators**
-   Shorter-than-expected periods for some seed states
-   Lack of uniformity of distribution for large quantities of generated numbers
-   Correlation of successive values
-   Poor dimensional distribution of the output sequence
-   Distances between where certain values occur are distributed differently from those in a random sequence distribution.


**Cryptographicaly Secured Random Number Generators**\
A PRNG suitable for cryptographic applications is called a cryptographically secure PRNG (CSPRNG). A requirement for a CSPRNG is that an adversary not knowing the seed has only negligible advantage in distinguishing the generator's output sequence from a random sequence. In other words, while a PRNG is only required to pass certain statistical tests, a CSPRNG must pass all statistical tests that are restricted to polynomial time in the size of the seed. Most PRNG algorithms produce sequences that are uniformly distributed by any of several tests. It is an open question, and one central to the theory and practice of cryptography, whether there is any way to distinguish the output of a high-quality PRNG from a truly random sequence. In this setting, the distinguisher knows that either the known PRNG algorithm was used (but not the state with which it was initialized) or a truly random algorithm was used, and has to distinguish between the two.


**Evaluation Criteria**\
-   K1 : *There should be a high probability that generated sequences of random numbers are different from each other.*
-   K2 : *A sequence of numbers is indistinguishable from "truly random" numbers according to specified statistical tests. The tests are the                monobit test (equal numbers of ones and zeros in the sequence), poker test (a special instance of the chi-squared test), runs test (counts          the frequency of runs of various lengths), longruns test (checks whether there exists any run of length 34 or greater in 20 000 bits of             the sequence)—both from BSI and NIST, and the autocorrelation test.*
-   K3 :  *It should be impossible for an attacker to calculate, or otherwise guess, from any given subsequence, any previous or future values in the sequence, nor any inner state of the generator.
-   K4 : *It should be impossible, for all practical purposes, for an attacker to calculate, or guess from an inner state of the generator, any previous numbers in the sequence or any previous inner generator states.*


**Applications**\
PRNGs are central in applications such as simulations (e.g. for the Monte Carlo method), electronic games (e.g. for procedural generation), and cryptography.


**Examples**\
ACORN\
Mersenne Twister\
xorshift generators\
WELL family of generators\
CryptGenRandom\
Yarrow algorithm\
Fortuna\
Blum Blum Shub algorithm\
Naor-Reingold pseudorandom function\


The following (non-exhaustive) list of websites claim to provide random numbers generated from a truly random source, with many providing additional randomisation services: 
-   Australian National University[37]
-   HotBits
-   Humboldt University of Berlin (registration required)
-   random.org