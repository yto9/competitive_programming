#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll K, N; cin >> K >> N;
    ll max_dis = 0;
    vector<ll> v;
    REP(i, N) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
    }
    REP(i, N) {
        ll dist;
        if (i == 0) {
            dist = v[0] + K - v[N-1];
        }
        else dist = v[i] - v[i-1];
        max_dis = max(max_dis, dist);
    }
    cout << K - max_dis << endl;
    return 0;
}
