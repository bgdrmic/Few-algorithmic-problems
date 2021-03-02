#include <cstdio>
#include <vector>
using namespace std;
 
 
vector<int> buba[100010];
bool musko[100010], bio[100010];
 
 
bool Popravi(int bub, int spol)
{
    if(bio[bub]) return 1;
    bio[bub] = 1;
    musko[bub] = spol;
    for(int i = 0; i < buba[bub].size(); i++)
    {
        if(bio[buba[bub][i]] && musko[buba[bub][i]] == spol) return 0;
        if(!Popravi(buba[bub][i], !spol)) return 0;
    }
    return 1;
}
 
 
int main()
{
    int a, b, m, n, t;
    bool rez;
    scanf("%d", &t);
    for(int o = 0; o < t; o++)
    {
        rez = 1;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            buba[i].clear();
            bio[i] = 0;
            musko[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            buba[a-1].push_back(b-1);
            buba[b-1].push_back(a-1);
        }
        for(int i = 0; i < n; i++) if(!Popravi(i, 1)) rez = 0;
        if(rez) printf("Scenario #%d:\nNo suspicious bugs found!\n", o+1);
        else printf("Scenario #%d:\nSuspicious bugs found!\n", o+1);
    }
    return 0;
}