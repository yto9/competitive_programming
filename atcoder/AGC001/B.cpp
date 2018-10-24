#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

ll one_side(ll a, ll b) { // a >= b
    if (a % b == 0) return a;
    else  return a/b * b + one_side(b, a % b);
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, X; cin >> N >> X;
    ll ma = max(X, N - X);
    ll mi = min(X, N - X);
    ll one_unit = one_side(ma, mi);
    ll res = 3 * one_unit;
    cout << res << endl;
    return 0;
}
