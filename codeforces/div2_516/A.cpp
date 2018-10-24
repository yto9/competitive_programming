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
    int a, b, c; cin >> a >> b >> c;
    int max_abc = max(max(a,b),max(b,c));
    int res = (max_abc < a+b+c - max_abc)? 0: (max_abc + 1) - (a+b+c - max_abc);
    cout << res << endl;
    return 0;
}
