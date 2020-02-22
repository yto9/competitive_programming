#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> renga;
    int res = 0;
    int idx = 1;
    REP(i, N) {
        ll tmp; cin >> tmp;
        renga.push_back(tmp);
    }
    for (auto x: renga) {
        if (x == idx) {
            idx++;
        }
        else {
            res++;
        }
    }
    if (res == N) res = -1;
    cout << res << endl;
    return 0;
}
