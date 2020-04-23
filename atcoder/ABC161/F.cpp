#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> yakusuu;
    ll N_1 = N;
    while(N_1 % 2 == 0) {
        N_1/=2;
        yakusuu.push_back()
    }
    for (ll i = 3; i*i <= N; i+=2) {
        while (N_1 % i == 0) {
            N_1/=i;
            mp_N[i]++;
        }
    }
    map<ll,ll> mp_N_1;
    N_1 = N - 1;
    while(N_1 % 2 == 0) {
        N_1/=2;
        mp_N_1[2]++;
    }
    for (ll i = 3; i*i <= N; i+=2) {
        while (N_1 % i == 0) {
            N_1/=i;
            mp_N_1[i]++;
        }
    }

    ll res_N_1 = 1;
    for (auto x: mp_N_1) {
        res_N_1 *= x.second;
    }
    for (auto x: mp_N) {
        
    }
    cout << res_N_1 -1 + << endl;
    return 0;
}
