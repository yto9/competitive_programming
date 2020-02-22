#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> v;
    ll res = 100000000000;
    REP(i, N) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    REP(i, 101) {
        ll tmp_res = 0;
        for (auto x: v) {
            tmp_res += (x-i)*(x-i);
        }
        res = min(res,tmp_res);
    }
    cout << res << endl;
    return 0;
}
