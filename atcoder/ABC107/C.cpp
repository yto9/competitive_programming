#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N, K; cin >> N >> K;
    vector <int> x;
    REP(i,N) {
        int tmp; cin >> tmp;
        x.push_back(tmp);
    }
    int res = INT_MAX;
    REP(i , N - (K - 1)) {
        int xl = x[i];
        int xr = x[i + (K - 1)];
        if (xl < 0) {
            if (xr <= 0){
                res = min(res, -xl);
            } 
            else {
                int time = min(-2*xl + xr, -xl + 2*xr);
                res = min(res, time);
            }
        }
        else {
            res = min(res, xr);
        }
    }
    cout << res << endl;
    return 0;
}
