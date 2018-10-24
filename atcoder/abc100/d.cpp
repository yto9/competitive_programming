#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 10000000009

typedef long long ll;
int n,m;

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    priority_queue<ll> q[8];
    REP(i, n) {
            ll x,y,z; cin >> x >> y >> z;
            q[0].push(x+y+z);
            q[1].push(-x+y+z);
            q[2].push(x-y+z);
            q[3].push(x+y-z);
            q[4].push(-x-y+z);
            q[5].push(-x+y-z);
            q[6].push(x-y-z);
            q[7].push(-x-y-z);
    }
    ll s[8];
    REP(i,8) {
        s[i] = 0;
    }
    REP(i, m) {
        REP(j,8) {
            ll x = q[j].top();q[j].pop();
            s[j] += x;
        }
    }
    ll res = -1;
    REP(i,8){
        res = max(res, s[i]);
    }
    cout << res << '\n';
    return 0;
}
