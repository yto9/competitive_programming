#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
// ll mod_pow(ll x, ll n, ll mod){//x^n % mod
//     if (n == 0)
//         return 1;
//     ll res = mod_pow(x * x % mod, n / 2, mod);
//     if (n & 1)
//         res = res * x % mod;
//     return res;
// }
typedef pair<int,int> p; // l, r
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    priority_queue<pair<int,int>> pq_r_l;
    priority_queue<pair<int,int>> pq_l_r;
    vector<p> v;
    int n; cin >> n;
    REP(i,n) {
        int l,r; cin >> l >> r;
        v.emplace_back(make_pair(l,r));
        pq_r_l.push(make_pair(r-l,i));
        pq_l_r.push(make_pair(l-r,-i));
    }
    vector<int> d(n+1);
    auto s = pq_r_l.top();
    d[n] = s.second;
    int idx = 0;
    while(idx < n) {
        auto src = pq_r_l.top();pq_r_l.pop();
        auto dest = pq_l_r.top();pq_l_r.pop();
        d[idx++] = src.second;
        if (idx >= n) break;
        d[idx++] = -dest.second;
    }
    ll res = 0;
    REP(i, n) {
        res += min(v[d[i]].first, v[d[i+1]].second);
    }
    cout << res << endl;
    return 0;
}
