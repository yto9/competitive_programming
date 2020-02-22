#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int res[300][300];  
vector<string> cake;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int H, W, K; cin >> H >> W >> K;
    
    REP(i,H){
        REP(j,W) {
            res[i][j] = 0;        }
    }
    REP(i,H) {
        string l; cin >> l;
        cake.push_back(l);
    }
    int idx = 1;
    REP(ca, H) {
        REP(i, W){
            bool pr = true;
            bool po = true;
            if (cake[ca][i] == '#'){
                res[ca][i] = idx;
                int j = 1;
                while(i-j>=0 || i+j < W){
                    if (pr && i-j>=0 && cake[ca][i-j] == '.' && res[ca][i-j] == 0) res[ca][i-j] = idx;
                    else pr = false;
                    if (po && i+j< W && cake[ca][i+j] == '.' && res[ca][i+j] == 0) res[ca][i+j] = idx;
                    else po = false;
                    j++;
                    if (pr == po && pr == false) break;
                }
                idx++;
            }
        }
    }
    //i行目に一個もいちごがないパターンの扱い
    REP(i,H) {
        bool pu = true;
        bool pd = true;
        if (i == 0) pu = false;
        if (i == H - 1) pd = false;
        if (res[i][0] == 0) {
            int j = 1;
            while(i-j >= 0 || i + j < H) {
                if (pu && i-j >= 0) {
                    if(res[i-j][0] != 0){
                        REP(a,W) {res[i][a] = res[i-j][a];}
                        break;
                    }
                }
                else pu = false;
                if (pd && i+j < H) {
                    if(res[i+j][0] != 0){
                        REP(a,W) {res[i][a] = res[i+j][a];}
                        break;
                    }
                }
                else pd = false;
                j++;
            }
        }
    }
    cerr << "------res-------" << endl;
    REP(i,H){
        REP(j,W) {
            if (j == W-1) cout << res[i][j] << endl;
            else cout << res[i][j] << " ";
        }
    }
    return 0;
}
