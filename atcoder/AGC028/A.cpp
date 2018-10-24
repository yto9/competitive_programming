#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
// ll mod_pow(ll x, ll n, ll mod){//x^n % mod
//     if (n == 0)
//         return 1;
//     ll res = mod_pow(x * x % mod, n / 2, mod);
//     if (n & 1)
//         res = res * x % mod;
//     return res;
// }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, M; cin >> N >> M;
    ll g = gcd(N, M);
    ll kou = (N/g) * (M/g) * g;
    string S, T;
    cin >> S;
    cin >> T;
    for (int i = 0, j = 0; i < (int)S.size() && j < (int)T.size(); i += kou/M, j += kou/N) {
        if (S[i] == T[j]) {
            continue;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << kou << endl;
    return 0;
}
