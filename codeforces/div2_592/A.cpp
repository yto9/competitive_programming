#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int t; cin >> t;
    REP(i, t){
        int a,b,c,d,k; cin >> a >> b >> c >> d >> k;
        int res_1 = 0;
        int res_2 = 0;
        REP(i,k+1) {
            if (a - c * i <= 0) {
                res_1 = i;
                break;
            }
        }
        REP(i,k+1-res_1){
            if (b -  d * i <= 0) {
                res_2 = i;
                break;
            }
        }
        if (res_1 * res_2 == 0){
            cout << -1 << endl;
        }
        else {
            cout << res_1 << " " << res_2 << endl;
        }
    }
    return 0;
}
