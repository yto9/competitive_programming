#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string S; cin >> S;
    string ans = "AC\n";
    int cnt = 0; 
    int L = S.size();
    if (S[0] != 'A') ans = "WA\n";
    FOR(i, 1, L){
        if (isupper(S[i])){
            if (i == 1 || i == L - 1 || S[i] != 'C'){
                ans = "WA\n";
            }
            cnt++;
        }
    }
    if (cnt != 1) ans = "WA\n";
    cout << ans;
    return 0;
}
