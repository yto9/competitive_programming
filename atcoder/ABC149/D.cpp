#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, K; cin >> N >> K;
    ll R, S, P; cin >> R >> S >> P;
    string T; cin >> T;
    string res;
    REP(i, N) {
        if (i < K) {
            if (T[i] == 'r') res.push_back('P');
            else if (T[i] == 's') res.push_back('R');
            else if (T[i] == 'p') res.push_back('S');
        }
        else {
            if (T[i] == 'r'){
                if(res[i-K] != 'P') res.push_back('P');
                else if (i+K < N && T[i+K] == 's') res.push_back('S');
                else res.push_back('R');
            }
            else if (T[i] == 's'){ 
                if(res[i-K] != 'R') res.push_back('R');
                else if (i+K < N && T[i+K] == 'p') res.push_back('P');
                else res.push_back('S');
            }
            else if (T[i] == 'p') {
                if(res[i-K] != 'S') res.push_back('S');
                else if (i+K < N && T[i+K] == 'r') res.push_back('R');
                else res.push_back('P');
            }
        }
    }
    ll ans = 0;
    REP(i,N) {
        if (T[i] == 'r' && res[i] == 'P') ans += P;
        else if(T[i] == 's' && res[i] == 'R') ans += R;
        else if(T[i] == 'p' && res[i] == 'S') ans += S;
    }
    cout << ans << endl;
    return 0;
}
