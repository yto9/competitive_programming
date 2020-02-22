    #include <bits/stdc++.h>
     
    using namespace std; 
    #define REP(i, n) for (int i = 0; i < (n); i++)
    #define MOD 1000000007
    typedef long long ll;
    ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
    ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
    int main(int argc, char const *argv[])
    {
        cin.tie(0);
       	ios::sync_with_stdio(false);
        ll N; cin >> N;
        vector<ll> v;
        ll lc = 1;
        REP(i, N) {
            ll tmp; cin >> tmp;
            v.push_back(tmp);
            lc = lcm(lc, tmp);
        }
        ll res = 0;
        REP(i, N) {
            res += (lc / v[i]) % MOD;
            res %= MOD;
        }
        cout << res << endl;
        return 0;
    }