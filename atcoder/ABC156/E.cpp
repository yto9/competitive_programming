#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll solve(ll n, ll k) {
    ll res = 0;
    REP(i, min(n,k+1)) {
        ll tmp = (COM(n, i) * COM(n-1, (n-i)-1)) % MOD;
        res += tmp;
        res %= MOD;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    COMinit();
    cout << solve(n,k) << endl;
    return 0;
}
