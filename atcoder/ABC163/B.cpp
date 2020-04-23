#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, M; cin >> N >> M;
    ll sum = 0;
    REP(i, M) {
        ll tmp; cin >> tmp;
        sum += tmp;
    }
    cout << max(-1LL, N - sum) << endl;
    return 0;
}
