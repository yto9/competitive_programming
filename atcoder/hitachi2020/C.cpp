#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> v;
    REP(i, N-1) {
        int src, dst; cin >> src >> dst;
    }
    REP(i,N) {
        v.push_back(i+1);
    }
    do {
        REP(i, (int)v.size()) {
            cout << v[i];
            if (i != (int)v.size() - 1) cout << " ";
        }
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));
    return 0;
}
