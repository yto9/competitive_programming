#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
// #define mod 1000000007
#define MOD (int)1e9+7
typedef long long ll;

ll modPow(ll a, int p) {// a^p (mod mod)
    if (p == 0) return 1;
    if (p%2 == 0) {
        int halfP = p/2;
        ll half = modPow(a, halfP);
        return half * half % (MOD);
    }
    else {
        ll ans = a * modPow(a, p - 1);
        return ans % (MOD);
    }
}

ll calcComb(int n, int r) {
    r = min(r, n-r);
    ll mulMod = 1;
    ll divMod = 1;
    for (int i = 0; i < r; i++) {
        mulMod *= (n - i);
        divMod *= (i + 1);
        mulMod %= (MOD);
        divMod %= (MOD);
    }
    ll ans = mulMod * modPow(divMod, MOD -2);
    return  ans % (MOD);
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    int restM = M;
    ll res = 1;
    for (int i = 2; i * i < M; i++) {
        if (restM % i == 0) {
            int cnt = 1;
            restM /= i;
            while (restM % i == 0) {
                cnt++; restM /= i;
            }
            res *= calcComb(cnt + N - 1,N-1);
            res %= (MOD);
        }
    }
    if (restM != 1) {
        res *= calcComb(1 + N - 1,N-1);
        res %= (MOD);
    }
    cout << res << endl;
    return 0;
}
