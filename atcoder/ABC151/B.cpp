#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N,K,M; cin >> N >> K >> M;
    ll target = N * M;
    REP(i, N-1){
        ll tmp; cin >> tmp;
        target-= tmp;
    }
    if (target < 0) cout << 0 << endl;
    else if (target <= K) cout << target << endl;
    else cout << -1 << endl;
    return 0;
}
