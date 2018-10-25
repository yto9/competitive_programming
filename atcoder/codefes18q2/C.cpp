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
    int n; cin >> n;
    char board[1002][1002];
    REP(i, 1002) {
        REP(j, 1002) {
            board[i][j] = '.';
            if ((i*2 + j)%5 == 0) board[i][j] = 'X';
        }
    }
    for(int i = 1; i <= n; i++) {
        if (board[i][0] == 'X') board[i][1] = 'X';
        if (board[i][n+1] == 'X') board[i][n] = 'X';
        if (board[0][i] == 'X') board[1][i] = 'X';
        if (board[n+1][i] == 'X') board[n][i] = 'X';
    } 

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
