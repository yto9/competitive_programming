#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    unordered_map<int, int> ump;
    int res = 0;
    REP(i, N) {
        int tmp; cin >> tmp;
        if(ump[tmp] > 0) res++;
        ump[tmp]++;
    }
    cout << res << endl;
    return 0;
}
