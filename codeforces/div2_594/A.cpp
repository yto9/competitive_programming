#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int t; cin >> t;
    REP(i, t) {
        ll n; cin >> n;
        ll cp_odd = 0;
        ll cp_even = 0;
        REP(i,n) {
            ll tmp; cin >> tmp;
            if (tmp%2==1) cp_odd++;
            else cp_even++;
        }
        ll cn_odd = 0;
        ll cn_even = 0;
        ll m; cin >> m;
        REP(i,m) {
            ll tmp; cin >> tmp;
            if (tmp%2==1) cn_odd++;
            else cn_even++;
        }
        cout << cp_odd * cn_odd + cp_even * cn_even << endl;
    }
    return 0;
}
