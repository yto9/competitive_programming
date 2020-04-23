#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll A, B, M; cin >> A >> B >> M;
    vector<ll> a;
    vector<ll> b;
    ll ans = 100000000;
    REP(i, A) {
        ll tmp; cin >> tmp;
        a.push_back(tmp);
    }
    REP(i, B) {
        ll tmp; cin >> tmp;
        b.push_back(tmp);
    }
    // 割引券使わないパターン
    ans = min(ans, a[distance(a.begin(),min_element(a.begin(), a.end()))] + b[distance(b.begin(),min_element(b.begin(), b.end()))]);
    REP(i, M) {
        ll x, y, c; cin >> x >> y >> c;
        ans = min(ans, (a[x-1] + b[y-1] - c));
    }
    cout << ans << endl;
    return 0;
}
