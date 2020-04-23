#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
typedef long long ll;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, K; cin >> N >> K;
    ll res = 0;
    for (ll i = 2; i <= K; i++) { //iが最大公約数
        ll k = K/i;
        if (k > 0) {
            ll g_i_res = pow(k,N) - pow(k - 1,N);//これだとgcd=1の場合があってなさそうだから上からdpしないとっぽい
            g_i_res %= MOD;
            g_i_res *= i;
            res += g_i_res % MOD;
            res %= MOD;
        }
    }
    cout << res << endl;
    return 0;
}
