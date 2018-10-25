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
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int t; cin >> t;
    REP(i,t) {
        int L, v, l ,r; cin >> L >> v >> l >> r;
        int num_of_lantern = L / v;
        int covered_lantern = r / v - (l - 1) / v;
        cout << num_of_lantern - covered_lantern << endl; 
    }
    return 0;
}
