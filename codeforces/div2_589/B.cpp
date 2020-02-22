#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007

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
    int h,w; cin >> h >> w;
    vector<int> R;
    vector<int> C;
    int board[1001][1001] = {0};
    REP(i, h) {
        int tmp; cin >> tmp;
        R.push_back(tmp);
    }
    REP(i, w) {
        int tmp; cin >> tmp;
        C.push_back(tmp);
    }
    REP(j, h){
        REP(i, R[j]) {
            board[j][i] = 1;
        }
        board[j][R[j]] = -1;
    }
    REP(i, w) {
        REP(j, C[i]){
            if (board[j][i] == -1) {
                cout << 0 << endl;
                return 0;
            }
            board[j][i] = 1;
        }
        if (board[C[i]][i] == 1) {
            cout << 0 << endl;
            return 0;
        }
        board[C[i]][i] = -1;
    }
    ll ans = 1;
    REP(j, h) {
        REP(i, w) {
            if(board[j][i] == 0) ans *= 2;
            ans %= MOD;  
        }
    }
    cout << ans << endl;
    return 0;
}
