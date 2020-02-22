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
    int H,W,A,B;
    cin >> H >> W >> A >> B;
    int res[1000][1000];
    REP(j, H){
        if (j < B){
            REP(i, W) {
                res[j][i] = 1;
            }
        }
        else {
            REP(i, W) {
                res[j][i] = 0;
            }
        }
    }
    REP(i, A) {
        REP(j, H) {
            if (res[j][i] == 0)
                res[j][i] = 1;
            else res[j][i] = 0;
        }
    }

    REP(j, H) {
        REP(i, W) {
            cout << res[j][i];
        }
        cout << "\n";
    }
    return 0;
}
