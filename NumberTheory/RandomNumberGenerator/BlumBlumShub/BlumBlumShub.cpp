#include <iostream>
using namespace std;

int main()
{
    int p = 31, q = 43; // blum primes;

    int n = p * q;  // module n

    int s = 3;  // seed

    int x0 = (s*s) % n;

    // generate 10 random bits
    int xi1 = x0;
    for(int i = 1; i <= 50; i++){
        int xi = (xi1 * xi1) % n;

        // parity
        int x = 0;
        while(xi > 0){
            x ^= xi&1;
            xi >>= 1;
        }

        // output
        cout << x << "\n";

        xi1 = (xi1 * xi1) % n;
    }
}
