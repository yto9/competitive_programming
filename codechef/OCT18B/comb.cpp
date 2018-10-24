#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
typedef long long ll;

ll mod_pow(ll x, ll n, ll mod){//x^n % mod
    if (x == 0LL) return 0LL;
    if (n == 0LL)
        return 1LL;
    ll res = mod_pow(x * x % mod, n / 2LL, mod) % mod;
    if (n & 1LL)
        res = res * x % mod;
    return res;
}

ll calcComb(ll n, ll r, ll mod) { // modを引数にする
    r = min(r, n-r);
    ll mulMod = 1LL;
    ll divMod = 1LL;
    for (ll i = 0LL; i < r; i++) {
        mulMod *= (n - i);
        divMod *= (i + 1LL);
        mulMod %= mod;
        divMod %= mod;
    }
    ll ans = mulMod * mod_pow(divMod, mod -2LL, mod) % mod;
    return  ans;
}
int main(int argc, char const *argv[])
{
    cout << calcComb(0,1,MOD) << endl;
    cout << calcComb(1,1,MOD) << endl;
    cout << calcComb(5,0,MOD) << endl;
    cout << calcComb(2,0,MOD) << endl;
    cout << calcComb(2,1,MOD) << endl;
    cout << calcComb(2,2,MOD) << endl;
    cout << calcComb(3,0,MOD) << endl;
    cout << calcComb(3,1,MOD) << endl;
    cout << calcComb(3,2,MOD) << endl;
    cout << calcComb(3,3,MOD) << endl;
    cout << calcComb(1000,0,MOD) << endl;
    cout << calcComb(1000,1,MOD) << endl;
    cout << calcComb(1000,499,MOD) << endl;
    cout << calcComb(1000,500,MOD) << endl;
    cout << calcComb(1000,501,MOD) << endl;
    cout << calcComb(1000,999,MOD) << endl;
    cout << calcComb(1000,1000,MOD) << endl;

    return 0;
}

