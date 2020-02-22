#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007LL

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> v(60,0);
    
    ll res = 0;
    REP(i, N){
        ll tmp; cin >> tmp;
        int idx = 0;
        while(tmp > 0) {
            if(tmp % 2) v[idx]++;
            tmp /= 2; idx++; 
        }
    }
    for(ll i = 0; i < 60 ; i++) {
        res += ((((v[i]%MOD) * ((N - v[i])%MOD))%MOD) * ((1LL << i) % MOD))%MOD;
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
