#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
using namespace std;

const int nsize = 1001;

list<int> prefL[nsize]; // preference list of left set
map<int,int> prefR[nsize]; // preference of right set

set<int> lmatch[nsize];    // engagements of left set
set<int> rmatch[nsize];    // engagements of right set

queue<int> que;

int main()
{
    int n;
    cin >> n;
    
    // preferences of left set
    for(int i = 1;i <= n;i++){
        int prefcnt;cin >> prefcnt;
        for(int j = 1;j <= prefcnt;j++){
            int percnt;cin >> percnt;
            for(int k = 1;k <= percnt;k++){
                int c;cin >> c;
                prefL[i].push_back(c);
            }
            prefL[i].push_back(0);
        }
        
    }
    
    // preferences of right set
    for(int i = 1;i <= n;i++){
        int prefcnt;cin >> prefcnt;
        for(int j = 1;j <= prefcnt;j++){
            int percnt;cin >> percnt;
            for(int k = 1;k <= percnt;j++){
                int c;cin >> c;
                prefL[i][c] = prefcnt;
            }
        }
    }
    
    
    // iterate
    while(true)
    {
        // init
        for(int i = 1;i <= n;i++){
            if(lmatch[i].size() == 0){que.push(i);}
        }
        
        
        while(que.size()){
            
            int li = que.front();
            que.pop();
            
            // empty preference list of li
            if(prefL[li].size() == 0){
                break;
            }
            
            // ri having same preference
            int ri = prefL[li].front();
            prefL[li].pop_front();
            
            while(ri != 0){
                
                if(rmatch[ri].size() == 0 || prefR[ri][li] == prefR[ri][rmatch[ri].front()]){
                    lmatch[li].push(ri);
                    rmatch[ri].push(li);
                }
                
                else if(prefR[ri][li] < prefR[ri][rmatch[ri].front()]){
                    // remove previous pairing
                    for(int lk : rmatch[ri]){
                        lmatch[lk].erase(ri);
                    }
                    rmatch[ri].clear();
                    
                    
                    lmatch[li].push(ri);
                    rmatch[ri].push(li);
                }
            }
        }
        
        for(int i = 1;i <= n;i++){
            if(prefL[i].size() == 0){
                cout << "No Super stable matching";
                lmatch[1].clear();
                break;
            }
        }
        
        bool allone = true;
        for(int i = 1;i <= n;i++){
            if(lmatch[i].size() > 1){allone = false;break;}
            if(rmatch[i].size() > 1){allone = false;break;}
        }
        
        if(allone){
            cout << "Super Stable matching found\n";
            break;
        }
        
        for(int i = 1;i <= n;i++){
            if(lmatch[i].size() > 1){
                // remove unsafe pairing
                for(int rk : lmatch[i]){
                    rmatch[rk].erase(i);
                }
                lmatch[i].clear();
            }
        }
    }
    
    if(lmatch[1].size())
    {
        for(int i = 1;i <= n;i++){
            cout << lmatch[i].front() << " ";
        }
    }
    
    // clear
    for(int i = 1;i <= n;i++){
        lmatch[i].clear();
        rmatch[i].clear();
    }
}