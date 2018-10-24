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
    int T; cin >> T;
    REP(i, T) {
        int N, K; cin >> N >> K;
        vector<int> v(N);
        REP(j, N) {
            cin >> v[j];
        }
        sort(v.rbegin(),v.rend());
        int res = K;
        int j = K;
        while(v[j++] == v[K-1]) {
            res++;
        }
        cout << res << endl;
    }
    return 0;
}
