#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

ll GCD(ll a, ll b) {
    if(b==0) return a;
    else return GCD(b, a % b);
}

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b==0){
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n, p, w, d; cin >> n >> p >> w >> d;
    ll k = GCD(w, d);
    if (p % k != 0) {
        cout << -1 << endl;
        return 0;
    }
    if (p == 0) {
        cout << "0 0 " << n << endl;
        return 0;
    }
    ll c = p / k;
    ll a = w / k;
    ll b = d / k;
    // ax + by = c , gcd(a,b) = 1 よりこの時点で整数解はもつ(負かもしれない)
    if (c == a * b) {
        cout << -1 << endl;
        return 0;
    }
    if (c < a + b) {
        cout << -1 << endl;
        return 0;
    }
    if (c > a * n) {
        cout << -1 << endl;
        return 0;
    }
    ll x,y;
    extGCD(a, b, x, y);
    // ax + by = 1 を満たす整数解x,yが入っている(負かも)

    ll res_x = c * x;
    ll res_y = c * y;
    
    if (res_x > n) {
        ll delta = (res_x - n)/b;
        res_x -= b*delta;
        res_y += a*delta;
    }
    else {
        ll delta = (n - res_x)/b;
        res_x += b*delta;
        res_y -= a*delta;
    }
    while (res_x >= 0)
    {
        if (res_y < 0) {
            ll delta = (-res_y)/a;
            res_y += a*delta;
            res_x -= b*delta;
        }
        if (res_x + res_y > n) {
            cout << -1 << endl;
            return 0;
        }
        if (res_y >= 0 && res_y + res_x <= n) {
            cout << res_x << " " << res_y << " " << n -res_x - res_y << endl;
            return 0;
        }
        res_y += a;
        res_x -= b;
    }
    cout << -1 << endl;

    return 0;
}
