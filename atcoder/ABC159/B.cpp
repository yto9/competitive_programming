#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string S; cin >> S;
    string ans = "No";
    int N = S.size();
    REP(i, N/2) {
        if (S[i] != S[N-1-i]) {
            cout << ans << endl;
            return 0;
        }
    }
    REP(i,N/4) {
        if (S[i] != S[N/2-1-i]) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
