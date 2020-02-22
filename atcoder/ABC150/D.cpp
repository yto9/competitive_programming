#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, M; cin >> N >> M;
    vector<ll> v;
    REP(i, N) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
    }
    // ll oddyou = 1;
    sort(v.begin(),v.end(),greater<ll>());
    ll beki = 0;
    // ll vmax = v[0];
    // ll vmin = v[N-1];
    ll kouyaku = 1;
    while(v[0]%(2*kouyaku) == 0) {
        beki++;
        // vmax/=2;
        kouyaku*=2;
    }
    if (v[N-1]%kouyaku != 0) {
        cout << 0 << endl;
        return 0;
    }
    // 2bekiは一緒
    ll k = 1;
    for (auto x: v){
        k = lcm(k,x/kouyaku);
    }
    ll res = 0;
    ll odd = 1;
    ll vm = v[0]/2;
    while(vm*odd <= M) {
        if (vm*odd % k == 0) res++;
        odd+=2;
    }
    cout << res << endl;
    return 0;
}
