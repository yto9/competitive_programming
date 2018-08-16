#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string S; cin >> S;
    int N; cin >> N;
    int l, r;
    auto itr = S.begin();
    REP(i, N) {
        cin >> l >> r;
        reverse(itr + (l - 1),itr + r);
    }
    cout << S << endl;
    return 0;
}
