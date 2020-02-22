#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

ll dfs(ll hp) {// hpのやつ1体を倒すのに必要な攻撃回数
    if (hp == 1) return 1;
    return dfs(hp/2) * 2 + 1;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll H; cin >> H;
    cout << dfs(H) << endl;
    return 0;
}
