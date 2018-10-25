#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<ll> v;
    REP(i, n) {
        ll tmp1, tmp2; cin >> tmp1 >> tmp2;
        v.push_back(lcm(tmp1,tmp2));
    }
    ll res = v[0];
    REP(i, n) {
        res = gcd(res, v[i]);
        if (res == 1) break;
    }
    if (res == 1) cout << -1 << endl;
    else {
        FOR(i,2,res + 1) {
            if (res % i == 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
