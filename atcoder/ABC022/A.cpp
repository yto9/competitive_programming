#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N, S, T; cin >> N >> S >> T;
    int w = 0;
    int res = 0;
    REP(i, N) {
        int tmp; cin >> tmp;
        w += tmp;
        if (S <= w && w <= T) res++;
    }
    cout << res << endl;
    return 0;
}
