#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    string S, T; cin >> S >> T;
    string res;
    REP(i, N) {
        res.push_back(S[i]);
        res.push_back(T[i]);
    }
    cout << res << endl;
    return 0;
}
