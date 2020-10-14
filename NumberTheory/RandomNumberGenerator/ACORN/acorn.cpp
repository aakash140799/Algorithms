#include <iostream>
#include <vector>
using namespace std;

vector<int> state1;
vector<int> state2;
int Acorn_M;

// set seed , M and internal state
void initSeed(int seed, int K, int M)
{
    state1.resize(0);
    state1.resize(K);

    state2.resize(0);
    state2.resize(K);

    state1[0] = seed;
    Acorn_M = M;
}

// generate random number
int ACORN()
{
    state2[0] = state1[0];
    for(int i = 1; i < state2.size(); i++){
        state2[i] = (state2[i-1] + state1[i]) % Acorn_M;
    }
    state1 = state2;

    return state1.back();
}

int main()
{
    // chose parameter M
    int M = 1<<10;

    // chose dimension K
    int K = 10;

    // seed and M should be co-prime
    int seed = 1;

    // initialize seed
    initSeed(1, K, M);

    // generate 30 random numbers
    for(int i = 0; i < 30; i++){
        cout << ACORN();
        cout << "\n";
    }
}
