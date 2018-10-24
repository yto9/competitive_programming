#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1e9+7

typedef long long ll;

ll d2[61][61];//2^iをj以上回割った時に出てくる要素数
ll cal(ll n, ll k, ll s) { // N 要素からなる　2^(k-1) ~ 2^kの値からs回以上割る
    if (n == 0) return 1LL;
    ll a = max(0LL, s-k);
    return (d2[k][a] * cal(n-1,k,s))% (ll)MOD; 
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N,K; cin >> N >> K;
    vector<ll> v;
    
    REP(i, N) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i <= 60; i++) {
        for (int j = i; j <=60; j++) {
            d2[i][j] = 1;
        }    
    }
    for (int i = 60; i >= 1; i--) {
        for (int j = 0; j <= 60; j++){
            if (d2[j][i-1] == 0) d2[j][i-1] = d2[j][i] + 1;
        }
    }
    ll res = 1;
    for (ll i = 1,ii = 1; ii < (ll)1e18; i++ ,ii *= 2) {
        auto l = lower_bound(v.begin(),v.end(),ii/2);
        auto r = upper_bound(v.begin(),v.end(),2);
        res *= cal(r-l,i-1,K) % (ll)MOD;
    }
    cout << res << endl;
    return 0;
}
