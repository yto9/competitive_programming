#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
typedef long long ll;
ll sum(ll N, ll x) {
    ll left = (1 + (x-1)) * (x-1)/2;
    ll right = N*x - left;
    return right - (left - 1);
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, K; cin >> N >> K;
    ll res = 0;
    for (int i = K; i <=N+1; i++) {
        res += sum(N,i) % MOD;
    }
    cout << res % MOD << endl;
    return 0;
}
