// BBRICKS
//列が繋がってると思っていた <- 問題なかった
// ピュアなスターリング数じゃない…似たようなDPというかパスカルの三角形？
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

ll P[1007][1007];
int main(int argc, char const *argv[])
{
    REP(i, 1007) {
        REP(j, 1007) {
            P[i][j] = 0;
        }
    }
    P[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        // S[i][0] = 1;// これは便宜上かな…
        P[i][1] = 1;// 1個のグループに分ける方法は1通り
        for(int j = 1; j < i; j++) {
            P[i][1+j] = P[i-1][j] + P[i-1][1+j]%MOD;
            P[i][1+j] %= MOD; 
        }
    } 
    int T; cin >> T;
    REP(test, T) {
        ll N, K; cin >> N >> K;
        if (N<K) {
            cout << 0 << endl;
            continue;
        }
        ll P2[1007];// N-K行目固定
        REP(i, 1007) {
            P2[i] = 0;
        }
        if (N-K <= 1000) { // 再利用
            REP(i, 1007) {
                P2[i] = P[N-K][i];
            }
        }
        else {
            REP(i,1007) {
                P2[i+1] = calcComb(N-K-1,i,MOD);
            }
        }
        ll P2_base = N - K; 
        ll res = 0LL;
        for (int i = 1; i <= K; i++) {
            if (N-K < i-1) break;
            ll blank_pattern = 0;
            for (int j = i-1; j <= i+1; j++) {
                ll addapt_pattern = (j == i)? 2 : 1;
                blank_pattern += addapt_pattern * P2[j] % MOD;
                blank_pattern %= MOD;
            }
            ll bricks_pattern = P[K][i] * mod_pow(2,i,MOD) % MOD;
            res += blank_pattern * bricks_pattern % MOD;
            res %= MOD;
        }
        cout << res << endl;
    }
    return 0;
}
