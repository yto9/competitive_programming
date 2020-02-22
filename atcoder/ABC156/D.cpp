#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007

typedef long long ll;
// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK)
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}
int COM[500000005] = {0};

void initCOM(ll n){
    REP(i, n/2 + 1) {
        if (i == 0) COM[i] = 1;
        for (int j = 1; j <= i; j++) {
            COM[j] += ((n - (j - 1)) * modinv(j,(ll)MOD))%MOD;
            COM[j] %= MOD;
        }
    }
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n, a, b; cin >> n >> a >> b;
    initCOM(n);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b) co    ntinue;
        res += COM[min((ll)i,n-i)];
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
