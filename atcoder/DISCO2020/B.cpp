#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
ll lef[200001];
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    
    lef[0] = 0;
    REP(i, N) {
        ll tmp; cin >> tmp;
        lef[i+1] = lef[i] + tmp; 
    }
    // lef[N] <- 全長
    ll res = 2020202020;
    REP(i, N) {
        res = min(res,llabs((lef[N] - lef[i+1] -lef[i+1])));
    }
    cout << res << endl;
    return 0;
}
