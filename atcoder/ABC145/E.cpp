#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<ll,ll> pll;

ll dfs(priority_queue<pll,vector<pll>,greater<pll>> pq, int rest) {
    if (rest <= 0 || pq.empty()) return 0;
    pll cur = pq.top();pq.pop();
    if (rest <= cur.first) {
        ll ma = cur.second;
        while(!pq.empty()){
            pll p = pq.top();pq.pop();
            ma = max(ma, p.second);
        }
        return ma;
    }
    ll use_cur = dfs(pq, rest - cur.first) + cur.second;
    ll unuse_cur = dfs(pq, rest);
    return max(use_cur,unuse_cur);
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, T; cin >> N >> T;
    priority_queue<pll,vector<pll>,greater<pll>> v_pqll;
    REP(i,N) {
        pll tmp;
        cin >> tmp.first >> tmp.second;
        v_pqll.push(tmp);
    }
    cout << dfs(v_pqll, T) << endl;
    return 0;
}
