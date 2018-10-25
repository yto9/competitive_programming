#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef pair<int,string> minus2;
typedef long long ll;
int main(int argc, char const *argv[])
{
    int N; cin >> N;
    vector<ll> limit;
    ll res = 0;
    int ans[34] = {0};
    ll beki = 1;
    limit.push_back(0);
    limit.push_back(1);
    for (int i = 0;limit.back()>-1e10;i++){
        beki *= -2;
        ll tmp = limit[i] + beki;
        limit.push_back(tmp);
    }
    if (N==0){
        cout << "0" << endl;
        return 0;
    }
    
    while(N!=0){
        if (N == 1) {
            ans[1] = 1;
            break;
        }
        REP (i, limit.size()){
            if (N > 0) {
                if (N <= limit[i]){
                    N -= limit[i] - limit[i - 2];
                    ans[i] = 1;
                    break;
                }
            }
            else if (N < 0) {
                if (N >= limit[i]){
                    N -= limit[i] - limit[i - 2];
                    ans[i] = 1;
                    break;
                }
            }
        }
    }
    int idx;
    string o;
    for (idx = 33; idx > 0; idx--) {
        if (ans[idx] == 1) break;
    }
    for (int i = idx; i>0; i--) {
        char c = (ans[i] == 0) ? '0':'1';
        o.push_back(c);
    }
    cout << o << endl;
    return 0;
}
