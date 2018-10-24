#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N, M, Q; cin >> N >> M >> Q;
    int l[502] = {};
    int r[502] = {};
    int L[502] = {};
    int R[502] = {};
    REP(i, M) {
        int tmp_l, tmp_r; cin >> tmp_l >> tmp_r;
        l[tmp_l]++;
        r[tmp_r]++;
    }
    L[0] = M;
    R[N + 1] = M;
    REP(i, N) {
        L[i + 1] = L[i] - l[i];
        R[N - i] = R[N - i + 1] - r[N - i + 1]; 
    }
    REP(i, Q){
        int tmp_l, tmp_r; cin >> tmp_l >> tmp_r;
        cout << min(L[tmp_l], R[tmp_r]) << endl;
    }
    return 0;
}
