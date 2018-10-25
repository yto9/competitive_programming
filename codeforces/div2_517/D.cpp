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
    int n, k; cin >> n >> k;
    char res[2*n-1];
    // multimap<int,int> mmp;// sum_of_idx, x; => can calc y
    // map<int,int> mp;
    vector<queue<pair<int,int>>> vq_kouho;
    for (int i = 0; i < 2*n-1;i++){
        res[i] = '?';
    }
    vector<string> board(n);
    REP(i, n) {
        cin >> board[i];
    }
    REP(j, 2*n-1) {//sum_of_idx
        REP(i,n) {//x
            if (board[j-i][i] == 'a') {
                vq_kouho
            }
        }
    }
    for (int sum_of_idx = 0; sum_of_idx < k; sum_of_idx++) {

    }
    return 0;
}
