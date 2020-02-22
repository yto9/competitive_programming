#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<ll,ll> pll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int M; cin >> M;
    vector<pll> v;
    ll keta = 0;
    ll souwa = 0;
    REP(i, M) {
        pll tmp; cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    for (auto x:v) {
        keta += x.second;
        souwa += x.first*x.second;
    }
    cout << keta - 1 + (souwa -1) / 9 << endl;
    return 0;
}
