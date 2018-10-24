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
ll fact[100007]; // n! mod p のテーブル O(p)
// n!=a p^e としたときの a mod p を求める。 O(log_p n)
ll mod_fact(ll n, ll p, ll& e) {
    e = 0;
    if (n == 0) return 1;
    // p の倍数の部分を計算
    int res = mod_fact(n / p, p, e);
    e += n / p;
    // (p-1)! ≡ -1 なので (p-1)!^(n/p) は n/p の偶奇だけで計算できる
    if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
    return res * fact[n % p] % p;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    return 0;
}
