#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, X; cin >> N >> X;
    vector<ll> v(200001);
    vector<ll> s(200001);
    s[0] = 0LL;
    for (ll i = 1LL; i <= N; i++) {
        cin >> v[i];
        s[i] = v[i] + s[i - 1LL];
    }
    ll res = LLONG_MAX;
    for (ll i = 1LL; i <= N; i++) {
        ll energy = LLONG_MIN + i * X;
        for (ll j = 0; j < N/i + 1; j++) {
            ll S = s[N - j * i] - s[max(N - (j + 1) * i, 0LL)];
            if(j == 0LL) energy += 5LL * S;
            else energy += (2LL*j + 3LL) * S;
        } 
        res = min(res, energy);
    }
    res += N * X + LLONG_MIN;
    cout << res << endl;
    return 0;
}
