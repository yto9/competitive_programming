#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string S; cin >> S;
    ll val = 0;
    ll res = 0;
    ll x = 0;
    while(x < (int)S.size()){
        while(S[x] == '<' && x <(int) S.size()) {
            val++;
            res += val;
            x++;
        }
        if (x == (int)S.size()) break;
        // cout << "after greater:" << res << endl;
        ll down = 0;
        ll pre_top = val;
        while (S[x] == '>' && x <(int) S.size()){
            val--;
            res += val;
            x++;
            down++;
        }
        // cout << "before lower:" << res << endl;
        if (val < 0) res -= (down+1) * val;
        else res -= down * val;
        // cout << "after lower:" << res << endl;
        val = 0;
    }
    cout << res << endl;
    return 0;
}
