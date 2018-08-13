#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int D,G; cin >> D >> G;
    int ans = 1e9;
    int p[10];
    int c[10];
    REP(i, D){
        cin >> p[i] >> c[i];
    }

    REP (mask, (1 << D)){
        int s = 0, num = 0, rest_max = -1;
        REP(i, D){
            if (mask >> i & 1){
                s += (i + 1) * 100 * p[i] + c[i];
                num += p[i];
            }
            else {
                rest_max = i;
            }
        }
        if (s < G){
            int s_m = 100 * (rest_max + 1);
            if (G - s <= s_m * (p[rest_max] - 1)) {
                num += (G - s)/ s_m + ((G - s) % s_m != 0);
            } 
            else continue;
        }
        ans = min(ans, num);
    }
    cout << ans << "\n";
    return 0;
}
