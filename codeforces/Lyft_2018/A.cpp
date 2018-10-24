#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int, int> P;
ll mod_pow(ll x, ll n, ll mod){//x^n % mod
    if (n == 0)
        return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1)
        res = res * x % mod;
    return res;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    P q; cin >> q.first >> q.second;
    P k; cin >> k.first >> k.second;
    P g; cin >> g.first >> g.second;
    if (((q.first - k.first) * (q.first - g.first) > 0) && ((q.second - k.second) * (q.second - g.second) > 0)) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
