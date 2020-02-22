#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
typedef long long ll;
ll mod_pow(ll x, ll n, ll mod){//x^n % mod
    if (n == 0)
        return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1)
        res = res * x % mod;
    return res;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    ll ans = mod_pow(mod_pow(2,m,MOD) - 1,n,MOD);
    cout << ans << endl;
    return 0;
}
