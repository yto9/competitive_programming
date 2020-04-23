#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    vector<int> v;
    map<int,ll> mp;
    int N; cin >> N;
    REP(i, N) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        mp[tmp]++;
    }
    ll res_sum = 0;
    for (auto x: mp) {
        res_sum += (x.second * (x.second - 1) )/ 2;
    }
    REP(i, N) {
        cout << res_sum - (mp[v[i]] - 1) << endl;
    }
    return 0;
}
