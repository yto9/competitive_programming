#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll a,b,x,y; cin >> a >> b >> x >> y;
    ll g_div = gcd(x,y);
    x /= g_div;
    y /= g_div;
    ll res = min(a/x, b/y);
    cout << res << endl;
    return 0;
}
