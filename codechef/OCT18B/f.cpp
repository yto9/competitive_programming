// BBRICKS
//列が繋がってると思っていた <- 問題なかった
#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007LL
typedef long long ll;

ll mod_pow(ll x, ll n, ll mod){//x^n % mod
    if (x == 0LL) return 0LL;
    if (n == 0LL)
        return 1LL;
    ll res = mod_pow((x % mod) * (x % mod) % mod, n / 2LL, mod) % mod;
    if (n & 1LL)
        res = res * (x % mod);
    return res % mod;
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
    int T; cin >> T;
    REP(test, T) {
        ll N, K; cin >> N >> K;
        ll res = 0LL;
        for (ll i = 1LL; i <= K; i++){
            if (N-K+1LL<i) break;
            ll blank = mod_pow(i+1,N-K-(i-1),MOD); 
            ll bbricks = mod_pow(2LL,i,MOD);//2^the number of bricks group
            bbricks *= mod_pow(i,K-i,MOD);// the rest K-i bricks can chose i group -> i^(K-i)だと数えすぎ
            bbricks %= MOD;
            cerr <<"i: " << i <<" blank: " << blank << " bricks: " << bbricks << " product: " << bbricks * blank %MOD << endl;
            res += bbricks * blank %MOD;
            res %= MOD;
        }
        cout << res << endl;
    }
    return 0;
}
