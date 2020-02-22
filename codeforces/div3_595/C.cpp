#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
ll num_3 (ll x) {
    ll beki = 0;
    while(x/3){
        x /= 3;
        beki++;
    }
    return beki;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int query; cin >> query;
    REP(q, query) {
        int beki3[40];
        REP (i, 40) {
            beki3[i] = 0;
        }
        ll n; 
        cin >> n;
        ll cur = n;
        while(cur > 0) {
            ll beki = num_3(cur);
            if (beki3[beki] == 0)beki3[beki]++;
            else {
                beki3[beki]--;
                beki3[beki+1]++;
                break;
            }
            ll kai3 = 1;
            REP(i, beki) kai3 *= 3;
            cur -= kai3; 
        }
        ll res = 0;
        REP(i, 40) {
            if (beki3[i] == 1) {
                ll kai3 = 1;
                REP(j,i) kai3 *= 3;
                res += kai3;
            }
            else if (beki3[i] == 2) {
                beki3[i+1]++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
