// BBRICKS
// 列を分離
#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007LL
typedef long long ll;

ll mod_pow(ll x, ll n, ll mod){//x^n % mod
    if (n == 0)
        return 1LL;
    ll res = mod_pow(x * x % mod, n / 2, mod) % mod;
    if (n & 1)
        res = res * x % mod;
    return res;
}

ll calcComb(ll n, ll r, ll mod) { // modを引数にする
    r = min(r, n-r);
    ll mulMod = 1;
    ll divMod = 1;
    for (ll i = 0; i < r; i++) {
        mulMod *= (n - i);
        divMod *= (i + 1);
        mulMod %= mod;
        divMod %= mod;
    }
    ll ans = mulMod * mod_pow(divMod, mod -2, mod);
    return  ans % mod;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int T; cin >> T;
    REP(test, T) {
        ll N, K; cin >> N >> K;
        ll res = 0LL;
        for(int i = 0; i <= K; i++) {
            if (N-i+1 >= i && N-(K-i)+1 >= K-i) {
                res += calcComb(N-i+1,i,MOD) * calcComb(N-(K-i)+1,K-i,MOD) % MOD;
                res %= MOD;
                cerr << i << ": " << calcComb(N-i+1,i,MOD) << " : " <<  calcComb(N-(K-i)+1,K-i,MOD) << endl;
            }
        }
        cout << res << endl;
    }
    return 0;
}
