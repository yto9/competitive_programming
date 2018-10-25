#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    int n,h,a,b,k; cin >> n >> h >> a >> b >> k;
    int ta[10000];
    int tb[10000];
    int fa[10000];
    int fb[10000];
    REP(i,k) {
        cin >> ta[i] >> fa[i] >> tb[i] >> fb[i];
    }
    
    REP(i,k) {
        ll res = 0;
        res += abs(ta[i]-tb[i]);
        if (ta[i] != tb[i]){
            if (fa[i] < a) {
                res += a - fa[i];
                fa[i] = a;
            }
            else if (fa[i] > b) {
                res += fa[i] - b;
                fa[i] = b;
            }
        }
        res += abs(fa[i]-fb[i]);
        cout << res << endl;
    }
    return 0;
}
