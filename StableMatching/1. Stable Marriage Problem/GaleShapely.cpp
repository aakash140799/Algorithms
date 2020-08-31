
#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;


const int nsize = 1e5 +1;

list<int> prefL[nsize];     // preference list of left set
map<int,int> prefR[nsize];  // preference map of right set, prefR[ri][li] = rank of li in ri's preference list

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