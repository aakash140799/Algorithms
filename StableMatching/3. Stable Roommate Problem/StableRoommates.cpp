#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

#define listi list<int>::iterator
const int nsize = 1001;

list<int>   pref[nsize];
listi       emap[nsize][nsize];
int         edel[nsize][nsize];
map<int,int> ranking[nsize];

int proposing[nsize];
int proposer[nsize];

map<int,int> vis;
queue<int> que;
list<int> alist;
list<int> blist;

void propose(int x,int y)
{
    proposing[x] = y;
    proposer[y] = x;
}

void reject(int y)
{
    int x = proposer[y];
    if(!edel[x][y]){pref[x].erase(emap[x][y]);edel[x][y]=1;}
    if(!edel[y][x]){pref[y].erase(emap[y][x]);edel[y][x]=1;}
    proposer[y] = 0;
    proposing[x] = 0;
}

void reject(int y,int x)
{
    if(!edel[x][y]){pref[x].erase(emap[x][y]);edel[x][y]=1;}
    if(!edel[y][x]){pref[y].erase(emap[y][x]);edel[y][x]=1;}
}

void reduce(int x, int n)
{
    if(proposer[x] == 0){return;}

    int y = proposer[x];
    for(int i = 1;i <= n;i++){
        if(i == x || i == y){continue;}

        if(ranking[x][y] < ranking[x][i]){reject(x, i);}
        if(ranking[i][proposer[i]] < ranking[i][x]){reject(i, x);}
    }
}

void showList(int n)
{
    for(int i = 1;i <= n;i++){
        cout << i << " : ";
        for(int x : pref[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;


    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n-1;j++){
            int c; cin >> c;

            pref[i].push_back(c);
            emap[i][c] = --(pref[i].end());
            ranking[i][c] = j;
            edel[i][c] = 0;
        }
        edel[i][i] = 1;
    }

    showList(n);
    cout << "input\n";

    for(int i = 1;i <= n;i++){
        que.push(i);
    }

    bool PrefEmpty = false;
    while(que.size())
    {
        int x = que.front();
        que.pop();

        while(proposing[x] == 0){
            if(pref[x].size() == 0){
                PrefEmpty = true;
                break;
            }

            int y = pref[x].front();
            if(proposer[y] == 0){
                propose(x, y);
            }
            else if(ranking[y][x] < ranking[y][proposer[y]]){
                que.push(proposer[y]);
                reject(y);

                propose(x, y);
            }else{reject(y, x);}
        }

        if(PrefEmpty){
            while(que.size()){
                que.pop();
            }
        }
    }

    showList(n);
    cout << "after proposing\n";

    if(PrefEmpty == false){
        for(int i = 1;i <= n;i++){
            reduce(i, n);
        }
        for(int i = 1;i <= n;i++){
            if(pref[i].size() == 0){PrefEmpty = true;}
            if(pref[i].size() > 1){que.push(i);}
        }

        if(PrefEmpty){
            while(que.size()){
                que.pop();
            }
        }
    }

    showList(n);
    cout << "after reduction\n";

    while(que.size())
    {
        int a1 = que.front();
        vis[a1] = 1;
        alist.push_back(a1);
        blist.push_back(0);

        while(true)
        {
            int an = alist.back();
            int bn1 = *(++(pref[an].begin()));
            int an1 = pref[bn1].back();

            if(vis.find(an1) == vis.end()){
                vis[an1] = 1;
                alist.push_back(an1);
                blist.push_back(bn1);
            }
            else
            {
                while(alist.front() != an1){
                    alist.pop_front();
                    blist.pop_front();
                }
                blist.front() = bn1;
                break;
            }
        }
        vis.clear();

        for(listi ai = alist.begin(), bi = blist.begin(); ai != alist.end(), bi != blist.end(); ai++, bi++){
            reject(*bi, *ai);
        }

        for(int x : alist){
            if(pref[x].size()==0){PrefEmpty = true;}
            else{propose(x, pref[x].front());}
        }

        while(que.size() && pref[que.front()].size() <= 1){que.pop();}

        if(PrefEmpty){
            while(que.size()){que.pop();}
        }

        for(int x : alist){cout << x << " ";}cout << "\n";
        for(int x : blist){cout << x << " ";}cout << "\n";
        showList(n);
        cout << "after reduction\n";

        alist.clear();
        blist.clear();
    }

    if(PrefEmpty){
        cout << "no stable matching\n";
    }
    else
    {
        cout << "stable matching found\n";
        for(int i = 1; i <= n; i++){
            if(i < proposing[i]){cout << i << " " << proposing[i] << "\n";}
        }
    }
}