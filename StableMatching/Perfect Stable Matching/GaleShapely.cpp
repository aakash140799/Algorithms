/*
    Algorithm : Gale Shapely Algorithm
    This algorithm solves perfect stable mathcing problem.
    
    Theory:
        Each person on left side propose person on right side to pair up with them, in order of their
        preference list. Each person of right side accepts the proposal if it is more preferable to them.
        Let us see how this intiution solves 1) Stable matching 2) complete matching
        
        Stable matching
            To see how an unstable matching be formed, let us consider the conditions that form
            an unstable matching.
            1)  there are two pairs (l1, r1), (l2, r2).
            2)  l1 is willing to pair up with r2.
            3)  r2 is also willing to pair up with l1
            To form an unstable matching, all three conditions must be satisfied.
                
            To see how algorithm provides a stable matching.
            Let us condsider the mathcing M found after running the algorithm.
            
            consider any person li on left side set who is paired up with person ri.
            let us see how li is paired with ri.
            
            1) Acc. to algorithm, li must have proposed all rj having more preferable(to li)
            than ri. Since li is not paired with any such rj, then all such rj must have
            accepted a more preferable(to rj) lj.
            Hence rj are not willing to pair with li, condition 3 fails.
            
            2) Acc. to algorithm, li did not proposed all rj having lower preferable(to li)
            than ri.
            Hence li is not willing to pair with any such rj, condition 2 fails.
            
            Hence in matching M, for every pairing, either codition 2 or 3 fails, so
            unstable matching is found.
            
        Compelte Mathcing
            Let us consider matching M found after running the algorithm
                1) Since every person on left side is paired with exactly one person.
                2) There are equal number of person on both sides.
            Every person on both sides must be paired up.
            
            
    
    Algorithm:
        make a queue
        add all left person in queue
        
        while queue is not empty
            front person proposes its top unproposed person
                if right person is unpaired
                    pair them up
                if right person is paired, but prefers front more
                    pair them up
                    add unpaired person to queue
                else
                    continue
                    
                    

    Time Complexity: O(n^2)
    Space Complexity : O(n^2)
    
    
    
    Note : In this algorithm, the proposing sides gets best pairing they can have, while proposed
    side gets the worst match they can have i.e left side gets their best right match, while right
    side gets their worst left match.
    
*/
#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;

const int nsize = 1e5 +1;
list<int> prefL[nsize];
map<int,int> prefR[nsize];

int lmatch[nsize];      // lmatch[i] = paired person of ith left person
int rmatch[nsize];      // rmatch[i] = paired person of ith right person


queue<int> que;

int main()
{
    int n;          // size of each group
    cin >> n;
    
    // preference list of left group person
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int t;cin >> t;
            prefL[i].push_back(t);
        }
    }
    
    // preference list of right group person
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int t;cin >> t;
            prefR[i][t] = j;
        }
    }
    
    // reset
    fill(lmatch, lmatch+n+1, 0);
    fill(rmatch, rmatch+n+1, 0);
    
    
    // push unpaired left
    for(int i = 1;i <= n;i++){
        que.push(i);
    }
    
    // make proposals
    while(que.size()){
        int li = que.front();
        que.pop();
        
        while(lmatch[li] == 0){
            int ri = prefL[li].front();
            prefL[li].pop_front();
            
            if(rmatch[ri] == 0){
                lmatch[li] = ri;
                rmatch[ri] = li;
            }
            else if(prefR[ri][li] < prefR[ri][rmatch[ri]]){
                lmatch[rmatch[ri]] = 0;
                lmatch[li] = ri;
                rmatch[ri] = li;
            }
        }
    }
    
    // output
    for(int i = 1;i <= n;i++){
        cout << lmatch[i] << " ";
    }cout << "\n";
    
    // clear
    for(int i = 1;i <= n;i++){
        prefL[i].clear();
        prefR[i].clear();
    }
}