#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N;
    vector<int> a;
    cin >> N;
    REP(i, N) {
        int x;cin >> x;
        a.push_back(x);
    }
    int pre = 0;
    int res = 0;
    REP(i, N) {
        if (pre == a[i]) {
            res++;
            pre = 0;
            continue;
        }
        pre = a[i];
    }
    cout << res << "\n";
    return 0;
}
