    #include <bits/stdc++.h>
     
    using namespace std;
    #define FOR(i, a, b) for (int i = (a); i < (b); i++) 
    #define REP(i, n) for (int i = 0; i < (n); i++)
     
    int res = 0;
    int p[10];
    int c[10];
    typedef pair<float, int> ex;
     
    priority_queue<ex> e;
     
    void solve(int D,int G) {
        if (G <= 0) return;
        ex tmp = e.top();
        int block = (tmp.second+1) * p[tmp.second] + c[tmp.second];
        if (block <= G) {
            res += p[tmp.second];
            e.pop();p[tmp.second] = 0;
            solve(D,G - block);
            return;
        }
        else {
            int idx = D;
            for (int i = D-1;i >= 0;i-- ){
                if (p[i]>0) {
                    idx = i; break;
                } 
            }
            if(G > (p[idx] -1) * idx){
                res += p[tmp.second];
                e.pop();p[tmp.second]=0;
                return;
            }
            else {
                res += G/idx;
                if (G % idx != 0) res+= 1;
                return;
            }
        }
        return;
    }
    int main(int argc, char const *argv[])
    {
        int D,G; cin >> D >> G;
        G /= 100;
        REP(i, D){
            cin >> p[i] >> c[i];
            c[i] /= 100;
            e.push(make_pair(i + 1 + c[i]/(float)p[i], i));
        }
     
        solve(D, G);
        cout << res << "\n";
        return 0;
    }