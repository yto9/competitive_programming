#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
using Graph = vector<vector<pair<int, bool>>>;
//まず
void dfs_root(Graph &G, int aok) {
    for(auto x: G[aok]) {
        for (pair<int,bool> y: G[x.first]) {
            if (y.first == x.first) {
                if (y.second == false) y.second = true;
                else return;
            }
        }
        dfs_root(G, x.first);
    }
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    int tak, aok; cin >> tak >> aok;
    Graph G(N);
    REP(i, N-1){
        int a, b; cin >> a >> b;
        G[a].push_back(make_pair(b,false));
        G[b].push_back(make_pair(a,false));
    }
    dfs_root(G,aok);
    return 0;
}
