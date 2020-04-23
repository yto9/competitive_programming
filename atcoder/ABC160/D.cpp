#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> res(N,0);
    REP(i, N) {
        REP(j, N) {
            if (j <= i) continue; // i < jを保証
            int dis = min(abs(j-i), abs(i-(X-1)) + 1 + abs(j-(Y-1)));
            res[dis]++;
        }
    }
    for (int i = 1; i < N; i++) {
        cout << res[i] << endl;
    }
    return 0;
}
