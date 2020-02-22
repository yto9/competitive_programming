#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, K; cin >> N >> K;
    vector<ll> v;
    REP(i, N) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),greater<ll>());
    ll num_attack = 0;
    for (ll i = K; i < N; i++) {
        num_attack += v[i];
    }
    cout << num_attack << endl;
    return 0;
}
