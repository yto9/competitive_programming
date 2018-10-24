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
    REP(i, 2 * N) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int res = 0;
    REP(i, N) {
        res += v[2*i];
    }
    cout << res << endl;
    return 0;
}
