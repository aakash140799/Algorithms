#include <iostream>
#include <queue>
using namespace std;

const int nsize = 1e5+1;
const int hsize = 1e5+1;

int ranking[nsize];     // rank of residents
queue<int> prefr[nsize];     // preference list of residents;
int assigned[nsize];        // hospital assigned to resident.


struct comprank
{
    bool operator()(int i1,int i2){
    return ranking[i1] < ranking[i2];}
};

int capacity[hsize];    // capacity room of hospitals
priority_queue<int, vector<int>, comprank> prefh[nsize];    // priority queue of residents assigned to hospitals


queue<int> unassigned;
int main()
{
    int n, m;
    cin >> n >> m;

    // ranking input
    for(int i = 1; i <= n; i++){
        cin >> ranking[i];
    }

    // preference list of residents
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;

        for(int j = 1; j <= k; j++){
            int h; cin >> h;
            prefr[i].push(h);
        }
    }

    // capacity input
    for(int i = 1; i <= m; i++){
        cin >> capacity[i];
    }


    // algorithm
    for(int i = 1; i <= n; i++){
        unassigned.push(i);
    }


    while(unassigned.size())
    {
        int ri = unassigned.front();
        unassigned.pop();

        while(prefr[ri].size() && assigned[ri] == 0)
        {
            int hi = prefr[ri].front();
            prefr[ri].pop();

            prefh[hi].push(ri);
            assigned[ri] = hi;

            if(prefh[hi].size() > capacity[hi]){
                int rj = prefh[hi].top();
                prefh[hi].pop();

                assigned[rj] = 0;
                if(rj != ri){unassigned.push(rj);}
            }
        }
    }

    // print assignement
    for(int i = 1; i <= n; i++){
        printf("%d is assigned to %d\n", i, assigned[i]);
    }

}
