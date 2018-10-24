#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int n,m; cin >> n >> m;
    priority_queue<int> party[3001];
    int unite = n;
    int min_cost = 0;
    REP(i,n) {
        int prefer, cost;
        cin >> prefer >> cost;
        // if (prefer == 1) unite++;
        if(prefer != 1) {
            party[prefer].push(cost);
            min_cost += cost;
        }
    }
    FOR(max_rival, 1 ,n){
        int possible = 0;
        priority_queue<int> top;
        FOR(i, 2, n+1){
            if (!party[i].empty()){
                possible++;
                int tmp = party[i].top();
                top.push(tmp);
            }
        }
        if (unite - possible > max_rival) {
            FOR(i, 2, n + 1){
                if(!party[i].empty()){
                    int c = party[i].top();party[i].pop();
                    min_cost -= c;
                    unite--;
                }
            }
        }
        else {
            while (unite > max_rival +1) {
                int c = top.top();top.pop();
                min_cost -= c;
                unite--;
            }
            break;
        }

    }
    cout << min_cost << endl;
    return 0;
}
