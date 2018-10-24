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
typedef pair<int, int> p;
char board[2007][2007];
p lim;
p st;
bool dfs(int r, int c, int L, int R, bool u, bool d) {//通ったところはkeepし到達出来たら全部!にする//始点の場合(L==lim.first&&R==lim.second)のみ到達出来なかったら始点のみ*にする
    // ->
    if(r == st.first && c == st.second) {
        return true;
    }
    if(R>0&&board[r+1][c] == '.' && dfs(r+1,c,L,R-1,false,false)) {
        board[r][c] = '!';
        return true;
    }
    // <-
    if(L>0&&board[r-1][c] == '.' && dfs(r-1,c,L-1,R,false,false)) {
        board[r][c] = '!';
        return true;
    }
    // ↑
    if(!d && board[r][c-1] == '.' && dfs(r,c-1,L,R,true,false)) {
        board[r][c] = '!';
        return true;
    }
    // ↓
    if(!u && board[r][c+1] == '.' && dfs(r,c+1,L,R,false,true)){
        board[r][c] = '!';
        return true;
    }
    if(L == lim.first && R == lim.second) {
        board[r][c] = '*';
    }
    return false;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    cin >> st.first >> st.second;// 1-index;
    cin >> lim.first >> lim.second;
    REP(i, 2007) {
        REP(j, 2007) {
            board[i][j] = '*';//番兵
        }
    }
    REP(i, n) {
        REP(j,n) {
            cin >> board[i][j];
        }
    }
    REP(i,n) {
        REP(j, m) {
            if (board[i][j] == '.') {
                dfs(i, j, lim.first, lim.second,false,false);
            }
        }
    }
    board[st.first][st.second] = '!';
    int res = 0;
    REP(i,n) {
        REP(j,m) {
            if(board[i][j] == '!') res++;
        }
    }
    cout << res << endl;
    return 0;
}
