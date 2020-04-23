#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, K, C; cin >> N >> K >> C;
    string S; cin >> S;
    int ans[K];
    ll cnt = 0;
    REP(i, N){
        if (cnt == K) break;
        if (S[i] == 'o') {
            ans[cnt] = i; cnt++;
            i += C;
        }
    }
    cnt = 0;
    vector<int> res;
    REP(i, N){
        if (cnt == K) break;
        if (S[N-1-i] == 'o') {
            cnt++;
            if (ans[K - cnt] == N-1-i) {
                res.push_back(N-i);
            }
            i += C;
        }
    }
    for (auto idx = res.rbegin(); idx != res.rend(); idx++){
        cout << *idx << endl;
    }
    cout << endl;
    return 0;
}
