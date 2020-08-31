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
queue<int> eraseQuel;
queue<int> eraseQuer;

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

            prefL[i].push_back(0);  // separator
        }

    }
    cout << "left preferences gathered : \n";
    for(int i = 1;i <= n;i++){
        cout << i << ": \n";
        for(int x : prefL[i]){
            if(x == 0){cout << "\n";}
            else{cout << x << " ";}
        }
    }

    // preferences of right set
    for(int i = 1;i <= n;i++){
        int prefcnt;cin >> prefcnt;

        for(int j = 1;j <= prefcnt;j++){
            int percnt;cin >> percnt;

            for(int k = 1;k <= percnt;k++){
                int c;cin >> c;
                prefR[i][c] = j;
            }
        }
    }
    cout << "right preferences gathered : \n";
    for(int i = 1;i <= n;i++){
        cout << i << ": \n";
        for(pair<int,int> x : prefR[i]){
            cout << x.first << "," << x.second << " ";
        }cout << "\n";
    }

    bool matchingfound = false;
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

                // ri is free
                if(rmatch[ri].size() == 0){
                    lmatch[li].insert(ri);
                    rmatch[ri].insert(li);
                }
                // ri equally prefer li
                else if(prefR[ri][li] == prefR[ri][*(rmatch[ri].begin())]){
                    lmatch[li].insert(ri);
                    rmatch[ri].insert(li);
                }
                // ri strictly prefer li
                else if(prefR[ri][li] < prefR[ri][*(rmatch[ri].begin())]){

                    // remove previous pairing
                    for(int lk : rmatch[ri]){
                        lmatch[lk].erase(ri);
                    }
                    rmatch[ri].clear();


                    lmatch[li].insert(ri);
                    rmatch[ri].insert(li);
                }

                ri = *(prefL[li].begin());
                prefL[li].pop_front();
            }
        }

        // check empty preference list
        for(int i = 1;i <= n;i++){
            if(prefL[i].size() == 0){
                break;
            }
        }

        // check possible super matching
        bool allone = true;
        for(int i = 1;i <= n;i++){
            if(lmatch[i].size() > 1){allone = false;break;}
            if(rmatch[i].size() > 1){allone = false;break;}
        }

        // all person are single paired
        if(allone){
            matchingfound = true;
            break;
        }

        // remove multiple engagements
        for(int i = 1;i <= n;i++){
            if(lmatch[i].size() > 1){eraseQuel.push(i);}
            if(rmatch[i].size() > 1){eraseQuer.push(i);}
        }

        while(eraseQuel.size()){
            int li = eraseQuel.front();
            eraseQuel.pop();

            for(int rk : lmatch[li]){
                rmatch[rk].erase(li);
            }
            lmatch[li].clear();
        }

        while(eraseQuer.size()){
            int ri = eraseQuer.front();
            eraseQuer.pop();

            for(int lk : rmatch[ri]){
                lmatch[lk].erase(ri);
            }
            rmatch[ri].clear();
        }
    }

    if(matchingfound){
        for(int i = 1;i <= n;i++){
            cout << *(lmatch[i].begin()) << " ";
        }cout << "\n";
    }else{cout << "No Super Stable matching found\n";}

    // clear
    for(int i = 1;i <= n;i++){
        lmatch[i].clear();
        rmatch[i].clear();
        prefL[i].clear();
        prefR[i].clear();
    }
}
