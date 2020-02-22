#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
typedef long long ll;
// ll mod_pow(ll x, ll n, ll mod){//x^n % mod
//     if (n == 0)
//         return 1;
//     ll res = mod_pow(x * x % mod, n / 2, mod);
//     if (n & 1)
//         res = res * x % mod;
//     return res;
// }
bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

ll phig(ll n, ll p) {
    ll ans = 1;
    ll count = 0;
    while(n/p > 0) {
        count++;
        for (int i = 0; i < count; i++){
            ans *= p;
            ans %= MOD
        }
        n /= p;
    }
    return ans % MOD;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll x,n; cin >> x >> n;
    ll ans = 1;
    if (IsPrime(x)){
        ans *= phig(n, x);
    }
    else {
        if (x % 2 == 0) {
            ans *= phig(n, 2);
            while(x % 2 == 0) {
                x /= 2;
            }
        }
        for (ll i = 3; i < x; i += 2) {
            if (x % i == 0) {
                ans *= phig(n, i);
                while(x % i == 0) {
                   x /= i;
                }
            } 
        }
    }
    cout << ans % MOD << endl;
    return 0;
}
