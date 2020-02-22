#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int q; cin >> q;
    REP(j,q){
        int n; cin >> n;
        vector<int> a;
        vector<pair<bool,int>> visted_loop;
        REP(i,n) {
            int tmp; cin >> tmp;
            a.push_back(tmp);
            visted_loop.push_back(make_pair(false,0));
        }
        REP(i, n) {            
            if(visted_loop[i].first) continue;
            visted_loop[i].first = true;
            int idx = i;
            int cnt = 1;
            vector<int> this_loop;
            this_loop.push_back(i);
            while(a[idx]-1 != i) {
                idx = a[idx]-1;
                this_loop.push_back(idx);
                visted_loop[idx].first = true;
                cnt++;
            }
            for(auto x: this_loop) {
                // if (visted_loop[x].first && visted_loop[x].second == 0) {
                    visted_loop[x].second = cnt;
                // }
            }
        }
        REP(i, n) {
            if (i != n-1) cout << visted_loop[i].second << " ";
            else cout << visted_loop[i].second << endl;
        }
    }
    return 0;
}
