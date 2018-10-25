#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    string S; cin >> S;
    ll K; cin >> K;
    char ans = '1';
    int f = (K > S.size()) ? S.size() : K;
    REP(i, f){
        if (S[i] != '1') {
            ans = S[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
