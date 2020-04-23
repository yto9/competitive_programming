#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, P; cin >> N >> P;
    string S; cin >> S;
    map<ll, ll> mp;
    vector<ll> beki10mod(N, 0);

    if (P == 2 || P == 5) {
        ll ans = 0;
        REP(i, N) {
            if ((S[i] - '0') % P == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    REP(i, N) {
        if (i == 0) beki10mod[i] = 1 % P;
        else beki10mod[i] = (beki10mod[i-1] * 10) % P;
    }
    ll ruiseki = 0;
    REP(i, N) {
        ruiseki += ((S[N-1-i] - '0') * beki10mod[i]) % P;
        ruiseki %= P;
        mp[ruiseki]++;
    }
    ll res = mp[0];
    ruiseki = 0;
    REP(i, N) {
        ruiseki += ((S[N-1-i] - '0') * beki10mod[i]) % P;
        ruiseki %= P;
        mp[ruiseki]--;
        res += mp[ruiseki];
    }
    cout << res << endl;
    return 0;
}
